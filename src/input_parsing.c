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

int	add_split(char *arg, t_cstack *cstack)
{
	char	**args;
	int		i;

	args = ft_split(arg, ' ');
	i = 0;
	while (args[i] != NULL)
	{
		if (is_num(args[i]))
			cstack_add(cstack, ft_atoi(args[i]));
		else
		{
			cstack_clear(cstack);
			ft_printf_fd("Error\n", 2);
			free_tab((void **)args, &free);
			free(cstack);
			return (-1);
		}
		i++;
	}
	free_tab((void **)args, &free);
	return (0);
}
// TODO check for dups

t_cstack	*parse_inputs(char **args)
{
	t_cstack	*cstack;

	cstack = ft_calloc(1, sizeof(t_cstack));
	cstack->name = 'a';
	while (args[0])
	{
		if (count_words(args[0], ' ') > 1)
		{
			if (add_split(args[0], cstack) == -1)
				return (NULL);
		}
		else if (is_num(args[0]))
			cstack_add(cstack, ft_atoi(args[0]));
		else
		{
			cstack_clear(cstack);
			free(cstack);
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
