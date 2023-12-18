/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/17 22:53:23 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_from_top(t_cstack_ptrs *element, t_cstack *cstack)
{
	t_cstack_ptrs	*start;
	t_cstack_ptrs	*stack;
	int			i;
	int			distance;

	stack = cstack->stack;
	start = stack;
	i = 0;
	while (stack != element)
	{
		stack = stack->next;
		i++;
	}
	distance = i;
	i = 0;
	while (start != element)
	{
		stack = stack->previous;
		i++;
	}
	return (distance <= i) * distance + (distance > i) * i *-1;
}

int	distance_from_pos(int num, t_cstack *stack)
{
}

int	sort(t_cstack *stack_a)
{
	t_cstack	*stack_b;
	int			size_a;
	int			size_b;

	size_a = cstack_size(stack_a);
	size_b = 0;
	pop_push(stack_a, stack_b, size_a, size_b);
	pop_push(stack_a, stack_b, size_a, size_b);
}
