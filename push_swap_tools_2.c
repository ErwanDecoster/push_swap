/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:35 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 14:07:39 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_tab(int len, char **tab)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i++]);
	}
	free(tab);
	return (1);
}

int	index_stack(t_data *data)
{
	t_stack	*elem;
	t_stack	*elem2;

	elem = data->stack_a;
	while (elem)
	{
		elem2 = data->stack_a;
		elem->index = 0;
		while (elem2)
		{
			if (elem2->content < elem->content)
				elem->index++;
			elem2 = elem2->next;
		}
		elem = elem->next;
	}
	return (0);
}

int	split_to_b(t_data *data, int len, int max_i, int min_i)
{
	int	med_i;

	med_i = (max_i + min_i) / 2;
	while (data->stack_a && data->size_b < len)
	{
		if (data->stack_a->index < max_i && data->stack_a->index >= min_i)
		{
			move_pb(data);
			if (data->stack_b->index < med_i)
				move_rb(data);
		}
		else
			move_ra(data);
	}
	return (0);
}

int	prepare_a(t_data *data, int len)
{
	while (len-- > 0)
		move_ra(data);
	return (0);
}

int	sort_b(t_data *data, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = find_max_position(data->stack_b);
		while (j <= data->size_b / 2 && j-- > 0)
			move_rb(data);
		while (j > data->size_b / 2 && j++ < data->size_b)
			move_rrb(data);
		move_pa(data);
		i++;
	}
	return (0);
}
