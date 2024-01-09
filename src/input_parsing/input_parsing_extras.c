/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_extras.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:12:53 by bplante/Wal       #+#    #+#             */
/*   Updated: 2024/01/09 13:21:23 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_string_int(char *str, int sign);

int	is_valid_num(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (ft_strlen(str) == 0)
		return (false);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (ft_strlen(str) == 1)
			return (false);
	}
	while (str[i] == '0')
		i++;
	if ((ft_strlen(&str[i]) == 10 && !is_string_int(&str[i], sign))
		|| ft_strlen(&str[i]) > 10)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

bool	is_string_int(char *str, int sign)
{
	int		i;
	char	*max_int;

	max_int = "2147483647";
	i = 0;
	while (i < 9)
	{
		if (str[i] > max_int[i])
			return (false);
		if (str[i] < max_int[i])
			return (true);
		i++;
	}
	if (sign > 0 && str[i] > max_int[i])
		return (false);
	else if (str[i] > max_int[i] + 1)
		return (false);
	return (true);
}
