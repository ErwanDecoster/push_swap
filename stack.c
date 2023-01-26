/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:25:49 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 16:27:00 by edecoste         ###   ########.fr       */
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
	nlist->next = 0;
	return (nlist);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*elem;

	elem = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	elem->next = new;
}

int	init_stack_a(t_data	*data, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
		stack_add_back(&data->stack_a, ft_stack_new(ft_atoi(argv[i])));
	data->size_a = i - 1;
	return (0);
}
