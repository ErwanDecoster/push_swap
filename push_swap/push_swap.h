/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:09 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/10 16:03:18 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_data
{
	int	value_count;
	int	*stack_a;
	int	*stack_b;
}	t_data;

void	move_sa(int *stack_a, int *stack_b);
void	move_sb(int *stack_a, int *stack_b);
void	move_ss(int *stack_a, int *stack_b);
void	move_pa(int *stack_a, int *stack_b);
void	move_pb(int *stack_a, int *stack_b);
void	move_ra(int *stack_a, int *stack_b);
void	move_rb(int *stack_a, int *stack_b);
void	move_rr(int *stack_a, int *stack_b);
void	move_rra(int *stack_a, int *stack_b);
void	move_rrb(int *stack_a, int *stack_b);
void	move_rrr(int *stack_a, int *stack_b);
// void	print_run(int *stack_a, int *stack_b, void (*move)(int *, int *), char *str);
int		ft_putstr(char *s);
int		ft_putchar(int c);
void	show_stack(int *stack, size_t len);
int		*arg_to_stack(t_data data, int argc, char **argv);
int		is_valid(char *arg, t_data data);
int		check_double(t_data data);

#endif