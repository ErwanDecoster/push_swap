/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:09 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/20 16:43:10 by edecoste         ###   ########.fr       */
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

int		go_algo(t_data *data);

// --------------------------------------------------------- push_swap_move_0 --

void	move_sa(t_data *data);
void	move_sb(t_data *data);
void	move_ss(t_data *data);

// --------------------------------------------------------- push_swap_move_1 --

void	move_pa(t_data *data);
void	move_pb(t_data *data);
void	move_ra(t_data *data);
void	move_rb(t_data *data);
void	move_rr(t_data *data);

// --------------------------------------------------------- push_swap_move_2 --

void	move_rra(t_data *data);
void	move_rrb(t_data *data);
void	move_rrr(t_data *data);

// ---------------------------------------------------------- push_swap_tools --

int		check_args(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		check_sort(int argc, char **argv);
int		check_max_min(char *str);
int		is_valid(char *arg);

// -------------------------------------------------------------------- close --

void	free_all(t_data *data);
int		error(void);
int		close_prog(void);
int		stop(void);

// -------------------------------------------------------------------- stack --

t_stack	*ft_stack_new(int content);
void	stack_add_back(t_stack **lst, t_stack *new);
void	stack_show(t_stack *lst);
int		init_stack_a(t_data	*data, int argc, char **argv);

#endif