/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:09 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 14:07:58 by edecoste         ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}	t_data;

// ---------------------------------------------------------------- push_swap --

int		go_algo(t_data *data);

// --------------------------------------------------------- push_swap_move_0 --

void	move_sa(t_data *data);
void	move_sb(t_data *data);//inused
void	move_ss(t_data *data);//inused

// --------------------------------------------------------- push_swap_move_1 --

void	move_pa(t_data *data);
void	move_pb(t_data *data);
void	move_ra(t_data *data);
void	move_rb(t_data *data);
void	move_rr(t_data *data);//inused

// --------------------------------------------------------- push_swap_move_2 --

void	move_rra(t_data *data);
void	move_rrb(t_data *data);
void	move_rrr(t_data *data);//inused

// ---------------------------------------------------------- push_swap_tools --

int		check_args(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		check_sort(int argc, char **argv);
int		check_max_min(char *str);
int		is_valid(char *arg);

// -------------------------------------------------------- push_swap_tools_2 --

int		find_min_val(t_stack *stack);
int		find_max_val(t_stack *stack);
int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);
int		find_i_position(t_stack *stack, int index);//inused

// -------------------------------------------------------- push_swap_tools_3 --

int		free_tab(int len, char **tab);
int		index_stack(t_data *data);
int		split_to_b(t_data *data, int len, int max_i, int min_i);
int		prepare_a(t_data *data, int len);
int		sort_b(t_data *data, int len);

// -------------------------------------------------------------------- close --

void	free_all(t_data *data);
void	free_stack(t_stack *stack);
int		error(void);
int		close_prog(void);
int		stop(t_data *data);

// -------------------------------------------------------------------- stack --

t_stack	*ft_stack_new(int content);
void	stack_add_back(t_stack **lst, t_stack *new);
void	stack_show(t_stack *lst);//inused
int		init_stack_a(t_data	*data, int argc, char **argv);

// ----------------------------------------------------------- sort_3_4_5_max --

int		sort_three(t_data *data);
int		move_i_to_b(t_data *data, int i, int len);
int		sort_four(t_data *data);
int		sort_five(t_data *data);
int		sort_max(t_data *data);

#endif