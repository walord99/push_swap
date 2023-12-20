/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:09:49 by bplante           #+#    #+#             */
/*   Updated: 2023/12/20 13:34:31 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// update to keep track of stack size
void	cstack_add(t_cstack *cstack, int num)
{
	t_cstack_ptrs	*new;
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	new = ft_calloc(1, sizeof(t_cstack_ptrs));
	new->num = num;
	if (!stack)
	{
		new->previous = new;
		new->next = new;
		stack = new;
	}
	if (stack->next == stack)
	{
		stack->next = new;
		stack->previous = new;
		new->next = stack;
		new->previous = stack;
	}
	else
	{
		new->previous = stack->previous;
		new->next = stack;
		stack->previous->next = new;
		stack->previous = new;
	}
	cstack->stack = stack;
	cstack->size++;
}

void	cstack_clear(t_cstack *cstack)
{
	t_cstack_ptrs	*start;
	t_cstack_ptrs	*temp;
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	start = stack;
	temp = stack;
	stack = stack->next;
	free(temp);
	while (stack != start)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	update_min_max(t_cstack *cstack)
{
	t_cstack_ptrs	*start;
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	start = stack;
	cstack->min = stack;
	cstack->max = stack;
	stack = stack->next;
	while (stack != start)
	{
		if (stack->num < cstack->min->num)
			cstack->min = stack;
		if (stack->num > cstack->max->num)
			cstack->max = stack;
		stack = stack->next;
	}
}
