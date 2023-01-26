/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:31:35 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/26 15:51:51 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (error());
	while (++i < argc)
		if (!is_valid(argv[i]))
			return (error());
	return (1);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (error());
	}
	return (1);
}

int	check_sort(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (1);
	return (close_prog());
}

int	check_max_min(char *str)
{
	if (ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
		return (0);
	return (1);
}

int	is_valid(char *arg)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(arg);
	if (len == 0 || (arg[0] != '-' && len > 10) || (arg[0] == '-' && len > 11))
		return (0);
	if (!check_max_min(arg))
		return (0);
	while (arg[++i])
	{
		if (arg[i] == '-' && !ft_isdigit(arg[i + 1]))
			return (0);
		if (ft_isdigit(arg[i]) && arg[i + 1] == '-')
			return (0);
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
	}
	return (1);
}
