/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/21 18:24:56 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**argv_cpy;
	int		argc_cpy;
	char	*join;

	argv_cpy = argv;
	argc_cpy = argc;
	if (argc == 2 && ft_strlen(argv[1]) > 1)
	{
		join = ft_strjoin("name ", argv[1]);
		argv_cpy = ft_split(join, ' '); // Leak probable
		argc_cpy = count_word(join, ' ');
	}
	check_args(argc_cpy, argv_cpy);
	check_duplicate(argc_cpy, argv_cpy);
	check_sort(argc_cpy, argv_cpy);
	init_stack_a(&data, argc_cpy, argv_cpy);
	// stack_show(data.stack_a);
	// free(argv_cpy);
	go_algo(&data);
	// ft_printf("OK");
	stop();
}

int	go_algo(t_data *data)
{
	// stack_show(data->stack_a);
	if (data->size_a == 3)
		sort_three(data);
	if (data->size_a == 5)
		sort_five(data);
	// stack_show(data->stack_a);
	return (0);
}

int sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->content;
	second = data->stack_a->next->content;
	third = data->stack_a->next->next->content;
	if (first > second && second > third && third < first)
		return (move_sa(data), move_rra(data), 0);
	else if (first > second && second < third && third > first)
		return (move_sa(data), 0);
	else if (first < second && second > third && third < first)
		return (move_rra(data), 0);
	else if (first < second && second > third && third > first)
		return (move_rra(data), move_sa(data), 0);
	else if (first > second && second < third && third < first)
		return (move_ra(data), 0);
	return (1);
}

int sort_five(t_data *data)
{
	ft_printf("value index {%d}", find_min_position(data->stack_a));
	return (0);
}

int	find_min_position(t_stack *stack)
{
	int	i;
	int	min_val;
	t_stack	*elem;

	i = 0;
	elem = stack;
	min_val = elem->content;
	while (elem->next != NULL)
	{
		if (elem->next->content < min_val)
			min_val = elem->next->content;
		elem = elem->next;
	}
	elem = stack;
	while (elem != NULL)
	{
		if (elem->content == min_val)
			break ;
		elem = elem->next;
		i++;
	}
	return (i);
}
