/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 15:12:59 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, **argv);
	check_duplicate(argc, **argv);
	check_sort(argc, **argv);
	init_stack_a(data);
	go_algo(data);



	
	
	data.value_count = count_total_arg(argc, argv);
	ft_printf("(%d)", data.value_count);
	// data.stack_a = ft_calloc(data.value_count, sizeof(int));
	if (!data.stack_a)
		error(&data);
	arg_to_stack(&data, argc, argv);
	// data.stack_b = ft_calloc(data.value_count, sizeof(int));
	// if (!data.stack_b)
		// error(&data);
	check_double(data);
	if(is_sorted(data, data.stack_a))
		stop(&data);
	show_stack(data.stack_a, data.value_count);
	stop(&data);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (stop());
	while (++i < argc)
	{
		if (!is_valide(argv[i]))
			return (stop());
	}
	return (1);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (argv[i] == argv[j])
				return (stop());
	}
	return (1);
}












void	*arg_to_stack(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (is_valid(argv[i], data))
		{
			t_stack *newElement;

			newElement = ft_stack_new(ft_atoi(argv[i]));
			stack_add_front(data->stack_a, newElement);
			// data->stack_a[j++] = ft_atoi(argv[i]);
		}
	}
	data->size_a = j;
// 	return (data->stack_a);
}

