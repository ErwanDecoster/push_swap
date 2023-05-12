/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/05/11 15:55:54 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*argv_restruct(int argc, char **argv)
{
	char	*join;
	char	**splitted;
	int		i;
	int		j;

	join = ft_strdup("name ");
	i = 0;
	while (++i < argc)
	{
		j = 0;
		splitted = ft_split(argv[i], ' ');
		while (j++ < count_word(argv[i], ' '))
		{
			join = ft_strjoin(join, splitted[j - 1]);
			free(splitted[j - 1]);
			if (!join)
				return (error("Error malloc\n"), NULL);
			join = ft_strjoin(join, " ");
			if (!join)
				return (error("Error malloc\n"), NULL);
		}
		free(splitted);
	}
	return (join);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		argc_cpy;
	char	*argv_str;
	char	**argv_cpy;

	if (argc < 2)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	argv_str = argv_restruct(argc, argv);
	argc_cpy = count_word(argv_str, ' ');
	argv_cpy = ft_split(argv_str, ' ');
	if (!argv_cpy)
		return (error("Error malloc\n"), 0);
	free(argv_str);
	if (!check_args(argc_cpy, argv_cpy) || !check_duplicate(argc_cpy, argv_cpy))
		return (free_tab(argc_cpy, argv_cpy), error("Error\n"));
	if (!check_sort(argc_cpy, argv_cpy))
		return (free_tab(argc_cpy, argv_cpy), close_prog());
	init_stack_a(&data, argc_cpy, argv_cpy);
	free_tab(argc_cpy, argv_cpy);
	go_algo(&data);
	stop(&data);
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
