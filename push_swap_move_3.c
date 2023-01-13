/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 14:23:45 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
// void	move_rra(t_data *data)
// {
// 	int	i;
// 	int	swap;

// 	i = data->size_a;
// 	swap = data->stack_a[data->size_a - 1];
// 	while (i > 0)
// 	{
// 		data->stack_a[i] = data->stack_a[i - 1];
// 		i--;
// 	}
// 	data->stack_a[0] = swap;
// 	ft_putstr_fd("rra\n", 1);
// }

// // rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// // la pile b. Le dernier élément devient le premier.
// void	move_rrb(t_data *data)
// {
// 	int	i;
// 	int	swap;

// 	i = data->size_b;
// 	swap = data->stack_b[data->size_b - 1];
// 	while (i > 0)
// 	{
// 		data->stack_b[i] = data->stack_b[i - 1];
// 		i--;
// 	}
// 	data->stack_b[0] = swap;
// 	ft_putstr_fd("rrb\n", 1);
// }

// // rrr : rra et rrb en même temps.
// void	move_rrr(t_data *data)
// {
// 	int	i;
// 	int	swap;

// 	i = data->size_a;
// 	swap = data->stack_a[data->size_a - 1];
// 	while (i > 0)
// 	{
// 		data->stack_a[i] = data->stack_a[i - 1];
// 		i--;
// 	}
// 	data->stack_a[0] = swap;

// 	i = data->size_b;
// 	swap = data->stack_b[data->size_b - 1];
// 	while (i > 0)
// 	{
// 		data->stack_b[i] = data->stack_b[i - 1];
// 		i--;
// 	}
// 	data->stack_b[0] = swap;
// 	ft_putstr_fd("rrr\n", 1);
// }
