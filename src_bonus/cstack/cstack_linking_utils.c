/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_linking_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:09:30 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:11:03 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_new_to_top(t_cstack_ptrs *element, t_cstack *dest)
{
	element->next = dest->stack;
	element->previous = dest->stack->previous;
	element->next->previous = element;
	element->previous->next = element;
}

void	link_new_1(t_cstack_ptrs *stack, t_cstack_ptrs *new)
{
	stack->next = new;
	stack->previous = new;
	new->next = stack;
	new->previous = stack;
}

void	link_new_gt1(t_cstack_ptrs *stack, t_cstack_ptrs *new)
{
	new->previous = stack->previous;
	new->next = stack;
	stack->previous->next = new;
	stack->previous = new;
}
