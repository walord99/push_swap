/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:27:25 by bplante           #+#    #+#             */
/*   Updated: 2023/12/26 02:38:28 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top2(t_cstack *cstack)
{
	t_cstack_ptrs	*rem_prev;
	t_cstack_ptrs	*rem_next;
	t_cstack_ptrs	*new_first;
	t_cstack_ptrs	*new_scnd;

	if (cstack->size < 3)
	{
		rotate(cstack);
		return ;
	}
	rem_prev = cstack->stack->previous;
	rem_next = cstack->stack->next->next;
	new_first = cstack->stack->next;
	new_scnd = cstack->stack;
	new_first->next = new_scnd;
	new_first->previous = rem_prev;
	rem_prev->next = new_first;
	new_scnd->previous = new_first;
	new_scnd->next = rem_next;
	rem_next->previous = new_scnd;
	cstack->stack = new_first;
}

void	update_min_max(t_cstack_ptrs *element, t_cstack *cstack)
{
	if (cstack->min == NULL || element->num < cstack->min->num)
		cstack->min = element;
	else if (cstack->max == NULL || element->num > cstack->max->num)
		cstack->max = element;
}

void	pop_push(t_cstack *src, t_cstack *dest)
{
	t_cstack_ptrs	*element;

	if (src->stack == NULL)
		return ;
	element = src->stack;
	src->size--;
	if (src->size != 0)
	{
		src->stack->next->previous = src->stack->previous;
		src->stack->previous->next = src->stack->next;
		src->stack = src->stack->next;
	}
	else
		src->stack = NULL;
	if (dest->stack == NULL)
	{
		element->next = element;
		element->previous = element;
	}
	else
		link_new_to_top(element, dest);
	dest->stack = element;
	dest->size++;
}
