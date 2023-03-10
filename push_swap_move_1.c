/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 16:29:23 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_ra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*elem;

	if (data->size_a > 1)
	{
		elem = data->stack_a;
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		while (elem->next)
			elem = elem->next;
		elem->next = tmp;
		tmp->next = 0;
		ft_printf("ra\n");
	}
}

void	move_rb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*elem;

	if (data->size_b > 1)
	{
		elem = data->stack_b;
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		while (elem->next)
			elem = elem->next;
		elem->next = tmp;
		tmp->next = 0;
		ft_printf("rb\n");
	}
}

void	move_rra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (data->size_a > 1)
	{
		tmp = data->stack_a;
		tmp2 = data->stack_a;
		while (tmp->next->next)
			tmp = tmp->next;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp->next = 0;
		tmp2->next = data->stack_a;
		data->stack_a = tmp2;
		ft_printf("rra\n");
	}
}

void	move_rrb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (data->size_b > 1)
	{
		tmp = data->stack_b;
		tmp2 = data->stack_b;
		while (tmp->next->next)
			tmp = tmp->next;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp->next = 0;
		tmp2->next = data->stack_b;
		data->stack_b = tmp2;
		ft_printf("rrb\n");
	}
}
