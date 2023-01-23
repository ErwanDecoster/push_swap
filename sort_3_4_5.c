/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:41:28 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/23 17:32:18 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int sort_four(t_data *data)
{
	move_i_to_b(data, find_min_position(data->stack_a), 5);
	sort_three(data);
	move_pa(data);
	return (0);
}

int sort_five(t_data *data)
{
	move_i_to_b(data, find_min_position(data->stack_a), 5);
	move_i_to_b(data, find_min_position(data->stack_a), 4);
	sort_three(data);
	move_pa(data);
	move_pa(data);
	return (0);
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

int	find_min_val(t_stack *stack)
{
	int	min_val;
	t_stack	*elem;

	elem = stack;
	min_val = elem->content;
	while (elem->next != NULL)
	{
		if (elem->next->content < min_val)
			min_val = elem->next->content;
		elem = elem->next;
	}
	return (min_val);
}

int	find_max_val(t_stack *stack)
{
	int	max_val;
	t_stack	*elem;

	elem = stack;
	max_val = elem->content;
	while (elem->next != NULL)
	{
		if (elem->next->content > max_val)
			max_val = elem->next->content;
		elem = elem->next;
	}
	return (max_val);
}

int	find_min_position(t_stack *stack)
{
	int	i;
	int	min_val;
	t_stack	*elem;

	i = 0;
	elem = stack;
	min_val = find_min_val(stack);
	while (elem != NULL)
	{
		if (elem->content == min_val)
			break ;
		elem = elem->next;
		i++;
	}
	return (i);
}