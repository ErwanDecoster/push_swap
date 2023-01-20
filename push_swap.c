/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/20 17:59:16 by edecoste         ###   ########.fr       */
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
	ft_printf("OK");
	stop();
}

int	go_algo(t_data *data)
{
	stack_show(data->stack_a);
	
	move_rrr(data);
	stack_show(data->stack_a);
	return (0);
}

int sort_three(t_data *data)
{
	if (data->stack_a->content > data->stack_a->next->content && data->stack_a->next->content > data->stack_a->next->next->content)
		return (move_sa(data), move_rra(data), 0);
	if (data->stack_a->content > data->stack_a->next->content && data->stack_a->next->content < data->stack_a->next->next->content)
		return (move_sa(data), 0);
}