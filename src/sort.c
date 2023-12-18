/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/18 15:36:58 by bplante          ###   ########.fr       */
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
		start = start->previous;
		i++;
	}
	return (distance <= i) * distance + (distance > i) * i *-1;
}

int	distance_from_pos(int num, t_cstack *stack)
{
	return 0;
}

void	sort(t_cstack *stack_a)
{
	t_cstack	*stack_b = ft_calloc(1, sizeof(t_cstack));

	pop_push(stack_a, stack_b);
	pop_push(stack_a, stack_b);
	pop_push(stack_a, stack_b);
}
