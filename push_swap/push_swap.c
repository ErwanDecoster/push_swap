/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/10 16:02:48 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_arg(int argc, char **argv)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while (++i < argc)
		rt += count_word(argv[i], ' ');
	return (rt);
}

void	free_all(t_data data)
{
	free(data.stack_a);
	free(data.stack_b);
}

int	error(t_data data)
{
	free_all(data);
	ft_printf("Error");
	exit(0);
	return (0);
}

int	stop(t_data data)
{
	free_all(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 0;
	data.value_count = count_total_arg(argc, argv);
	data.stack_a = ft_calloc(data.value_count, sizeof(int));
	if (!data.stack_a)
		error(data);
	data.stack_a = arg_to_stack(data, argc, argv);
	data.stack_b = ft_calloc(data.value_count, sizeof(int));
	if (!data.stack_b)
		error(data);
	check_double(data);
	show_stack(data.stack_a, data.value_count);
}

int	check_double(t_data data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data.value_count)
	{
		j = i;
		while (++j < data.value_count)
			if (data.stack_a[i] == data.stack_a[j])
				return (error(data));
	}
	return (1);
}

int	check_order(t_data data, int *stack)
{
	int	i;

	i = 0;
	while (i < data.value_count - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			stop(data);
	}
	return (1);
}

int	*arg_to_stack(t_data data, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**splited;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		j = 0;
		splited = ft_split(argv[i], ' ');
		while (j++ < count_word(argv[i], ' '))
			if (is_valid(splited[j - 1], data))
				data.stack_a[k++] = ft_atoi(splited[j - 1]);
	}
	return (data.stack_a);
}

int	is_valid(char *arg, t_data data)
{
	size_t	i;

	i = -1;
	if (ft_strlen(arg) == 0)
		return (error(data));
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (error(data));
	return (1);
}

// void	print_run(int *stack_a, int *stack_b, void (*move)(int *, int *), char *str)
// {
// 	ft_putstr(str);
// 	move(stack_a, stack_b);
// }

int	ft_putstr(char *s)
{
	size_t	i;
	int		rt_val;

	i = 0;
	rt_val = 0;
	if (!s)
		i = ft_putstr("(null)");
	else
	{
		while (s[i])
		{
			rt_val = ft_putchar(s[i++]);
			if (rt_val == -1)
				return (rt_val);
		}
	}
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
