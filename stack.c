/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:25:49 by edecoste          #+#    #+#             */
/*   Updated: 2023/02/03 17:05:02 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*nlist;

	nlist = malloc(sizeof(t_stack));
	if (!nlist)
		return (0);
	nlist->content = content;
	nlist->next = NULL;
	return (nlist);
}

void	stack_add_back(t_stack **stack, t_stack *add_new)
{
	t_stack	*temp;

	temp = *stack;
	if (!*stack)
	{
		*stack = add_new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = add_new;
	add_new->next = NULL;
}

int	init_stack_a(t_data	*data, int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 0;
	while (++i < argc)
	{
		stack = ft_stack_new(ft_atoi(argv[i]));
		if (!stack)
			return (error("Error malloc\n"), free_stack(data->stack_a), 0);
		stack_add_back(&data->stack_a, stack);
	}
	data->size_a = i - 1;
	return (0);
}
