/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:35 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 15:08:54 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(int *stack, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		ft_printf("%d\n", stack[i++]);
}

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

int	check_double(t_data data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data.value_count)
	{
		j = i;
		while (++j < data.value_count)
			if (data.stack_a[i].content == data.stack_a[j].content)
				return (error(&data));
	}
	return (1);
}

int	is_sorted(t_data data, t_stack **stack)
{
	int	i;

	i = 0;
	while (i < data.value_count - 1)
	{
		if (stack[i].content < stack[i + 1].content)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_valid(char *arg)
{
	int	i;

	i = -1;
	if (ft_strlen(arg) == 0)
		return (1);
	while (arg[++i])
	{
		if (arg[i] == '-' && !ft_isdigit(arg[i + 1]))
			return (1);
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (1);
	}
	return (0);
}