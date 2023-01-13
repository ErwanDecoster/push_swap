/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:09 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 15:07:47 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int		value_count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}	t_data;

int		move_sa(t_data *data);
int		move_sb(t_data *data);
int		move_ss(t_data *data);
void	move_pa(t_data *data);
void	move_pb(t_data *data);
void	move_ra(t_data *data);
void	move_rb(t_data *data);
void	move_rr(t_data *data);
void	move_rra(t_data *data);
void	move_rrb(t_data *data);
void	move_rrr(t_data *data);
// void	print_run(t_data data, void (*move)(int *, int *), char *str);
int		ft_putstr(char *s);
int		ft_putchar(int c);
void	show_stack(int *stack, size_t len);
int		*arg_to_stack(t_data *data, int argc, char **argv);
int		is_valid(char *arg, t_data *data);
int		is_sorted(t_data data, t_stack **stack);
int		check_double(t_data data);
int		count_total_arg(int argc, char **argv);

// ------------------------------------------------------------------------ close --

void	free_all(t_data *data);
int		error(t_data *data);
int		close(t_data *data);
int		stop();

// ------------------------------------------------------------------------ stack --

t_stack	*ft_stack_new(int content);
void	stack_add_front(t_stack **lst, t_stack *new);
void	stack_iter(t_stack *lst, void (*f)(void *));

#endif