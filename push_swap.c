/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/18 16:36:51 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	check_args(int argc, char **argv);
int	check_duplicate(int argc, char **argv);
int	check_sort(int argc, char **argv);

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
	stack_show(data.stack_a);
	ft_printf("\n\n");
	// move_sa(&data);
	move_rra(&data);
	stack_show(data.stack_a);
	// ft_printf("\n\n");
	// stack_show(data.stack_b);
	// free(argv_cpy);
	// go_algo(data);
	ft_printf("OK");
	stop();
}

int	init_stack_a(t_data	*data, int argc, char **argv)
{
	int	i;
	t_stack *new;
	i = 0;
	while (++i < argc)
	{
		new = ft_stack_new(ft_atoi(argv[i]));
		stack_add_back(&data->stack_a, new);
	}
	return (0);
}


// void	*arg_to_stack(t_data *data, int argc, char **argv)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (++i < argc)
// 	{
// 		if (is_valid(argv[i], data))
// 		{
// 			t_stack *newElement;

// 			newElement = ft_stack_new(ft_atoi(argv[i]));
// 			stack_add_front(data->stack_a, newElement);
// 			// data->stack_a[j++] = ft_atoi(argv[i]);
// 		}
// 	}
// 	data->size_a = j;
// // 	return (data->stack_a);
// }

