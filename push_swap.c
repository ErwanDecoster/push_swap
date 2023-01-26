/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 10:58:31 by edecoste         ###   ########.fr       */
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
	// free(argv_cpy);
	go_algo(&data);
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
	return (0);
}
