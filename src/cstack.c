/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:09:49 by bplante           #+#    #+#             */
/*   Updated: 2023/12/18 13:59:39 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//update to keep track of stack size
t_cstack	*cstack_add(t_cstack *cstack, int num)
{
	t_cstack	*new;

	new = ft_calloc(1, sizeof(t_cstack));
	new->num = num;
	if (!cstack)
	{
		new->previous = new;
		new->next = new;
		return (new);
	}
	if (cstack->next == cstack)
	{
		cstack->next = new;
		cstack->previous = new;
		new->next = cstack;
		new->previous = cstack;
	}
	else
	{
		new->previous = cstack->previous;
		new->next = cstack;
		cstack->previous->next = new;
		cstack->previous = new;
	}
	return (cstack);
}

void	cstack_clear(t_cstack *cstack)
{
	t_cstack_ptrs	*start;
	t_cstack_ptrs	*temp;
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	start = stack;
	while (stack != start)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	update_size(t_cstack *cstack)
{
	int			i;
	t_cstack_ptrs	*start;
	t_cstack_ptrs *stack;

	i = 0;

	stack = cstack->stack;
	start = cstack->stack;
	while (stack != start)
	{
		stack = stack->next;
		i++;
	}
	cstack->size = i;
	return (i);
}
