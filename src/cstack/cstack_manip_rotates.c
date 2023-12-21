/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack_manip_rotates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:15:52 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:17:46 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_cstack *stack)
{
	stack->stack = stack->stack->next;
	ft_printf("r%c\n", stack->name);
}

void	rotate_reverse(t_cstack *stack)
{
	stack->stack = stack->stack->previous;
	ft_printf("rr%c\n", stack->name);
}

void	rotate_both(t_cstack *stack_a, t_cstack *stack_b)
{
	stack_a->stack = stack_a->stack->next;
	stack_b->stack = stack_b->stack->next;
	ft_printf("rr\n");
}

void	rotate_reverse_both(t_cstack *stack_a, t_cstack *stack_b)
{
	stack_a->stack = stack_a->stack->previous;
	stack_b->stack = stack_b->stack->previous;
	ft_printf("rrr\n");
}
