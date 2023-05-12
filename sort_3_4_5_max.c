/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:41:28 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/27 13:29:58 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_data *data)
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

int	move_i_to_b(t_data *data, int i, int len)
{
	while (i <= len / 2 && i-- > 0)
		move_ra(data);
	while (i > len / 2 && i++ < len)
		move_rra(data);
	move_pb(data);
	return (0);
}

int	sort_four(t_data *data)
{
	move_i_to_b(data, find_min_position(data->stack_a), 5);
	sort_three(data);
	move_pa(data);
	return (0);
}

int	sort_five(t_data *data)
{
	move_i_to_b(data, find_min_position(data->stack_a), 5);
	move_i_to_b(data, find_min_position(data->stack_a), 4);
	sort_three(data);
	move_pa(data);
	move_pa(data);
	return (0);
}

int	sort_max(t_data *data)
{
	int	i;
	int	nb_chunck;
	int	chunck;
	int	sup;

	nb_chunck = data->size_a / 45 + 1;
	if (data->size_a > 400)
		nb_chunck = data->size_a / 90 + 1;
	i = nb_chunck;
	chunck = data->size_a / nb_chunck;
	sup = data->size_a - (data->size_a / nb_chunck * nb_chunck);
	while (i > 0)
	{
		split_to_b(data, chunck + sup, chunck * i + sup, chunck * i - chunck);
		sort_b(data, data->size_b);
		if (i > 1)
			prepare_a(data, chunck + sup);
		if (sup > 0)
			sup = 0;
		i--;
	}
	return (0);
}
