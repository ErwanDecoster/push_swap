/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/23 18:27:39 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**argv_cpy;
	int		argc_cpy;
	char	*join;

	argv_cpy = argv;
	argc_cpy = argc;
	if (argc == 2 && ft_strlen(argv[1]) > 1)
	{
		join = ft_strjoin("name ", argv[1]);
		argv_cpy = ft_split(join, ' '); // Leak probable
		argc_cpy = count_word(join, ' ');
	}
	check_args(argc_cpy, argv_cpy);
	check_duplicate(argc_cpy, argv_cpy);
	check_sort(argc_cpy, argv_cpy);
	init_stack_a(&data, argc_cpy, argv_cpy);
	// stack_show(data.stack_a);
	// free(argv_cpy);
	go_algo(&data);
	// ft_printf("OK");
	stop();
}

int	go_algo(t_data *data)
{
	if (data->size_a == 2)
		move_sa(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a == 4)
		sort_four(data);
	else if (data->size_a == 5)
		sort_five(data);
	else
	{
		index_stack(data);
		sort_max(data);
	}
	stack_show(data->stack_a);
	stack_show(data->stack_b);
	return (0);
}

int	sort_max(t_data *data)
{
	(void)data;
	ft_printf("pas fini\n");
	twenty_percent_mini(data);
	return (0);
}

int	index_stack(t_data *data)
{
	t_stack *elem;
	t_stack *elem2;

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
	ft_printf("index end\n");
	return (0);
}

int	twenty_percent_mini(t_data *data)
{
	int	i;
	int	len;
	int	moyen;

	i = 0;
	len = data->size_a;
	moyen = (find_min_val(data->stack_a) + find_max_val(data->stack_a)) / 2;
	while (i < len)
	{
		if (data->stack_a->content < moyen)
		{
			move_pb(data);
		}
		else
		{
			move_pb(data);
			move_rb(data);
		}
		// move_i_to_b(data, find_min_position(data->stack_a), data->size_a);
		i++;
	}
	return (0);
}