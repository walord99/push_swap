/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:27:25 by bplante           #+#    #+#             */
/*   Updated: 2023/12/18 16:17:05 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top2(t_cstack *cstack)
{	
	//u need pen paper for this	
}

void	pop_push(t_cstack *src, t_cstack *dest)
{
	t_cstack_ptrs	*element;

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
	{
		element->next = dest->stack;
		element->previous = dest->stack->previous;
		element->next->previous = element;
		element->previous->next = element;
	}
	dest->stack = element;
	dest->size++;
}

void	rotate(t_cstack *stack)
{
	stack->stack = stack->stack->next;
}

void	rotate_reverse(t_cstack *stack)
{
	stack->stack = stack->stack->previous;
}
