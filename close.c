/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:24:40 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 16:02:35 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_data *data)
{
	free_stack(data->stack_a);
	free_stack(data->stack_b);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	close_prog(void)
{
	exit(0);
	return (0);
}

int	stop(t_data *data)
{
	free_all(data);
	exit(0);
}
