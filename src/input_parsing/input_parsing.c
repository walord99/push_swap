/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:21:18 by bplante           #+#    #+#             */
/*   Updated: 2023/12/21 15:14:48 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_split(char *arg, t_cstack *cstack)
{
	char	**args;
	int		i;

	args = ft_split(arg, ' ');
	i = 0;
	while (args[i] != NULL)
	{
		if (is_valid_num(args[i]))
			cstack_add(cstack, ft_atoi(args[i]));
		else
		{
			cstack_clear(cstack);
			free_tab((void **)args, &free);
			free(cstack);
			return (-1);
		}
		i++;
	}
	free_tab((void **)args, &free);
	return (0);
}

bool	has_dup(t_cstack *cstack, t_cstack_ptrs *element)
{
	int	num;

	num = element->num;
	while (true)
	{
		if (num == element->next->num && element->next != cstack->stack)
			return (true);
		element = element->next;
		if (element == cstack->stack)
			return (false);
	}
}

t_cstack	*dup_checker(t_cstack *cstack)
{
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	while (true)
	{
		if (has_dup(cstack, stack))
			break ;
		stack = stack->next;
		if (stack == cstack->stack)
			return (cstack);
	}
	cstack_clear(cstack);
	free(cstack);
	return (NULL);
}

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
		else if (is_valid_num(args[0]))
			cstack_add(cstack, ft_atoi(args[0]));
		else
		{
			cstack_clear(cstack);
			free(cstack);
			return (NULL);
		}
		args++;
	}
	return (dup_checker(cstack));
}
