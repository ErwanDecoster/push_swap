/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:25:49 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/18 14:02:02 by edecoste         ###   ########.fr       */
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

void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
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

void	stack_show(t_stack *lst)
{
	int		i;
	t_stack	*elem;

	i = 0;
	elem = lst;
	while (elem != NULL)
	{
		ft_printf("%d, ", elem->content);
		elem = elem->next;
		i++;
	}
}
