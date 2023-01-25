/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/25 16:20:22 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_data *data)
{
	t_stack	*tmp;

	if (data->size_a > 1)
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = data->stack_a->next;
		data->stack_a->next = tmp;
		ft_printf("sa\n");
	}
}

void	move_sb(t_data *data)
{
	t_stack	*tmp;

	if (data->size_b > 1)
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = data->stack_b->next;
		data->stack_b->next = tmp;
		ft_printf("sb\n");
	}
}

void	move_ss(t_data *data)
{
	t_stack	*tmp;

	if (data->size_a > 1 && data->size_b > 1)
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = data->stack_a->next;
		data->stack_a->next = tmp;
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = data->stack_b->next;
		data->stack_b->next = tmp;
		ft_printf("ss\n");
	}
}
