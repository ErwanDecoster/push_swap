/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/12 14:23:12 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (argc < 2)
		return (0);
	i = 0;
	data.value_count = count_total_arg(argc, argv);
	data.stack_a = ft_calloc(data.value_count, sizeof(int));
	if (!data.stack_a)
		error(&data);
	data.stack_a = arg_to_stack(&data, argc, argv);
	data.stack_b = ft_calloc(data.value_count, sizeof(int));
	if (!data.stack_b)
		error(&data);
	check_double(data);
	if(is_ordered(data, data.stack_a))
		stop(&data);
	show_stack(data.stack_a, data.value_count);
	ft_printf("(%d)", data.size_a);
}

int	*arg_to_stack(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**splited;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		j = 0;
		splited = ft_split(argv[i], ' ');
		while (j++ < count_word(argv[i], ' '))
			if (is_valid(splited[j - 1], data))
				data->stack_a[k++] = ft_atoi(splited[j - 1]);
	}
	data->size_a = k;
	return (data->stack_a);
}
