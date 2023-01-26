/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 16:28:59 by edecoste         ###   ########.fr       */
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
