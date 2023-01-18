/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/18 16:39:42 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
void	move_rra(t_data *data)
{
	t_stack *tmp;
	t_stack *tmp2;
	
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

// // rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// // la pile b. Le dernier élément devient le premier.
void	move_rrb(t_data *data)
{
	t_stack *tmp;
	t_stack *tmp2;
	
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

// // rrr : rra et rrb en même temps.
void	move_rrr(t_data *data)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp = data->stack_a;
	tmp2 = data->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp->next = 0;
	tmp2->next = data->stack_a;
	data->stack_a = tmp2;

	tmp = data->stack_b;
	tmp2 = data->stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp->next = 0;
	tmp2->next = data->stack_b;
	data->stack_b = tmp2;
	ft_printf("rrr\n");
}
