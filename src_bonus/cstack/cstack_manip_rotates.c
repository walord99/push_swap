/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack_manip_rotates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:15:52 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/26 03:01:55 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_cstack *stack)
{
	if (stack->stack == NULL)
		return ;
	stack->stack = stack->stack->next;
}

void	rotate_reverse(t_cstack *stack)
{
	if (stack->stack == NULL)
		return ;
	stack->stack = stack->stack->previous;
}

void	rotate_both(t_cstack *stack_a, t_cstack *stack_b)
{
	if (stack_a->stack != NULL)
		stack_a->stack = stack_a->stack->next;
	if (stack_b->stack != NULL)
		stack_b->stack = stack_b->stack->next;
}

void	rotate_reverse_both(t_cstack *stack_a, t_cstack *stack_b)
{
	if (stack_a->stack != NULL)
		stack_a->stack = stack_a->stack->previous;
	if (stack_b->stack != NULL)
		stack_b->stack = stack_b->stack->previous;
}
