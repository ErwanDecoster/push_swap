/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:02:07 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 14:23:18 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Utiliser des listes chainé

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// int	move_sa(t_data *data)
// {
// 	int	swap;

// 	if (!data->stack_a[0] || !data->stack_a[1])
// 		return (0);
// 	swap = data->stack_a[0];
// 	data->stack_a[0] = data->stack_a[1];
// 	data->stack_a[1] = swap;
// 	ft_putstr_fd("sa\n", 1);
// 	return (1);
// }

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// int	move_sb(t_data *data)
// {
// 	int	swap;

// 	if (!data->stack_b[0] || !data->stack_b[1])
// 		return (0);
// 	swap = data->stack_b[0];
// 	data->stack_b[0] = data->stack_b[1];
// 	data->stack_b[1] = swap;
// 	ft_putstr_fd("sa\n", 1);
// 	return (1);
// }

// ss : sa et sb en même temps.
// int	move_ss(t_data *data)
// {
// 	int	swap;

// 	if (!data->stack_a[0] || !data->stack_a[1])
// 		return (0);
// 	swap = data->stack_a[0];
// 	data->stack_a[0] = data->stack_a[1];
// 	data->stack_a[1] = swap;

// 	if (!data->stack_b[0] || !data->stack_b[1])
// 		return (0);
// 	swap = data->stack_b[0];
// 	data->stack_b[0] = data->stack_b[1];
// 	data->stack_b[1] = swap;
// 	ft_putstr_fd("ss\n", 1);
// 	return (1);
// }

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
// void	move_pa(t_data *data)
// {
// 	int	i;

// 	i = data->size_a;
// 	if (data->size_a > 0)
// 	{
// 		while (i > 0)
// 		{
// 			data->stack_a[i] = data->stack_a[i - 1];
// 			i--;
// 		}
// 		data->stack_a[0] = data->stack_b[0];
// 		data->size_a++;
// 		i = 0;
// 		while (i < data->size_b - 1)
// 		{
// 			data->stack_b[i] = data->stack_b[i + 1];
// 			i++;
// 		}
// 		data->size_b--;
// 		data->stack_b[i] = 0;
// 	}
// 	ft_putstr_fd("pa\n", 1);
// }
