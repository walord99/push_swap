/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:21:18 by bplante           #+#    #+#             */
/*   Updated: 2023/12/19 23:16:31 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str);

// TODO check for dups
t_cstack	*parse_inputs(char **args)
{
	t_cstack	*cstack;

	cstack = ft_calloc(1, sizeof(t_cstack));
	cstack->name = 'a';
	while (args[0])
	{
		if (is_num(args[0]))
			cstack_add(cstack, ft_atoi(args[0]));
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
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
