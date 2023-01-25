/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/25 16:26:30 by edecoste         ###   ########.fr       */
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
	// free(argv_cpy);
	go_algo(&data);
	stop();
}

int	go_algo(t_data *data)
{
	if (data->size_a == 2)
		move_sa(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a == 4)
		sort_four(data);
	else if (data->size_a == 5)
		sort_five(data);
	else
	{
		index_stack(data);
		sort_max(data);
	}
	return (0);
}

int	index_stack(t_data *data)
{
	t_stack	*elem;
	t_stack	*elem2;

	elem = data->stack_a;
	while (elem)
	{
		elem2 = data->stack_a;
		elem->index = 0;
		while (elem2)
		{
			if (elem2->content < elem->content)
				elem->index++;
			elem2 = elem2->next;
		}
		elem = elem->next;
	}
	return (0);
}

int	split_to_b(t_data *data, int len, int max_index, int min_index)
{
	int	direction;
	int	med_index;

	direction = 0;
	med_index = (max_index + min_index) / 2;
	while (data->stack_a && data->size_b < len)
	{
		if (data->stack_a->index < max_index && data->stack_a->index >= min_index)
		{
			move_pb(data);
			if (data->stack_b->index < med_index)
				move_rb(data);
		}
		else if (direction == 0)
			move_ra(data);
		else if (direction == 1)
			move_rra(data);
		if (data->stack_a->index > max_index)
			direction = 1;
	}
	return (0);
}

int	sort_b(t_data *data, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = find_max_position(data->stack_b);
		while (j <= data->size_b / 2 && j-- > 0)
			move_rb(data);
		while (j > data->size_b / 2 && j++ < data->size_b)
			move_rrb(data);
		move_pa(data);
		i++;
	}
	return (0);
}
