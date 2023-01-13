/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 14:23:34 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
// void	move_pb(t_data *data)
// {
// 	int	i;

// 	i = data->size_b;
// 	if (data->size_b > 0)
// 	{
// 		while (i > 0)
// 		{
// 			data->stack_b[i] = data->stack_b[i - 1];
// 			i--;
// 		}
// 		data->stack_b[0] = data->stack_a[0];
// 		data->size_b++;
// 		i = 0;
// 		while (i < data->size_a - 1)
// 		{
// 			data->stack_a[i] = data->stack_a[i + 1];
// 			i++;
// 		}
// 		data->size_a--;
// 		data->stack_a[i] = 0;
// 	}
// 	ft_putstr_fd("pb\n", 1);
// }

// // ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// // Le premier élément devient le dernier.
// void	move_ra(t_data *data)
// {
// 	int	i;
// 	int	swap;

// 	i = 0;
// 	swap = data->stack_a[0];
// 	while (i < data->size_a)
// 	{
// 		data->stack_a[i] = data->stack_a[i + 1];
// 		i++;
// 	}
// 	data->stack_a[data->size_a - 1] = swap;
// 	ft_putstr_fd("ra\n", 1);
// }

// // rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// // Le premier élément devient le dernier.
// void	move_rb(t_data *data)
// {
// 	int	i;
// 	int	swap;

// 	i = 0;
// 	swap = data->stack_b[0];
// 	while (i < data->size_b)
// 	{
// 		data->stack_b[i] = data->stack_b[i + 1];
// 		i++;
// 	}
// 	data->stack_b[data->size_b - 1] = swap;
// 	ft_putstr_fd("rb\n", 1);
// }

// // rr : ra et rb en même temps.
// void	move_rr(t_data *data)
// {
// 	int	i;
// 	int	swap;

// 	i = 0;
// 	swap = data->stack_a[0];
// 	while (i < data->size_a)
// 	{
// 		data->stack_a[i] = data->stack_a[i + 1];
// 		i++;
// 	}
// 	data->stack_a[data->size_a - 1] = swap;
	
// 	i = 0;
// 	swap = data->stack_b[0];
// 	while (i < data->size_b)
// 	{
// 		data->stack_b[i] = data->stack_b[i + 1];
// 		i++;
// 	}
// 	data->stack_b[data->size_b - 1] = swap;
// 	ft_putstr_fd("rr\n", 1);
// }
