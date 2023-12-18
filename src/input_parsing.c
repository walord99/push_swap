/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:21:18 by bplante           #+#    #+#             */
/*   Updated: 2023/12/15 14:22:01 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str);

t_cstack	*parse_inputs(char **args)
{
	t_cstack	*cstack;
	int			num;

	cstack = NULL;
	while (args[0])
	{
		if (is_num(args[0]))
			cstack = cstack_add(cstack, ft_atoi(args[0]));
		else
		{
			cstack_clear(cstack);
			ft_printf_fd("Error\n", 2);
			return (NULL);
		}
		args++;
	}
	return (cstack);
}

int	is_num(char *str)
{
	while (str[0])
	{
		if (!ft_isdigit(str[0]))
			return (false);
		str++;
	}
	return (true);
}
