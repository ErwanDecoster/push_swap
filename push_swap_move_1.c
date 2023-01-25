/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/25 16:20:41 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_data *data)
{
	t_stack	*tmp;

	if (data->size_b > 0)
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = data->stack_a;
		data->stack_a = tmp;
		data->size_b--;
		data->size_a++;
		ft_printf("pa\n");
	}
}

void	move_pb(t_data *data)
{
	t_stack	*tmp;

	if (data->size_a > 0)
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = data->stack_b;
		data->stack_b = tmp;
		data->size_a--;
		data->size_b++;
		ft_printf("pb\n");
	}
}

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

void	move_rr(t_data *data)
{
	t_stack	*tmp;
	t_stack	*elem;

	if (data->size_a > 1 && data->size_a > 1)
	{
		elem = data->stack_a;
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		while (elem->next)
			elem = elem->next;
		elem->next = tmp;
		tmp->next = 0;
		elem = data->stack_b;
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		while (elem->next)
			elem = elem->next;
		elem->next = tmp;
		tmp->next = 0;
		ft_printf("rr\n");
	}
}
