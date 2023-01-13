/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:24:40 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 15:04:56 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
}

int	error(t_data *data)
{
	free_all(data);
	ft_printf("Error\n");
	exit(0);
	return (0);
}

int	close(t_data *data)
{
	free_all(data);
	exit(0);
}

int	stop()
{
	exit(0);
}