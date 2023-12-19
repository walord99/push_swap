/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:09:49 by bplante           #+#    #+#             */
/*   Updated: 2023/12/18 22:00:39 by bplante/Wal      ###   ########.fr       */
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

	cstack->min = INT_MAX;
	cstack->max = INT_MIN;
	stack = cstack->stack;
	start = stack;
	if (stack->num < cstack->min)
		cstack->min = stack->num;
	if (stack->num > cstack->max)
		cstack->max = stack->num;
	stack = stack->next;
	while (stack != start)
	{
		if (stack->num < cstack->min)
			cstack->min = stack->num;
		if (stack->num > cstack->max)
			cstack->max = stack->num;
		stack = stack->next;
	}
}
