/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/20 16:43:35 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Utiliser des listes chainé

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
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

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
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

// ss : sa et sb en même temps.
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
