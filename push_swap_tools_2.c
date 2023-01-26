/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:35 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 11:23:09 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_val(t_stack *stack)
{
	int		min_val;
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
	int		max_val;
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
	int		i;
	int		min_val;
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

int	find_max_position(t_stack *stack)
{
	int		i;
	int		max_val;
	t_stack	*elem;

	i = 0;
	elem = stack;
	max_val = find_max_val(stack);
	while (elem != NULL)
	{
		if (elem->content == max_val)
			break ;
		elem = elem->next;
		i++;
	}
	return (i);
}

int	find_i_position(t_stack *stack, int index)
{
	int		i;
	t_stack	*elem;

	i = 0;
	elem = stack;
	while (elem)
	{
		if (elem->index == index)
			break ;
		elem = elem->next;
		i++;
	}
	return (i);
}
