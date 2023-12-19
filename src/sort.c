/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/19 00:30:47 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_from_top(t_cstack_ptrs *element, t_cstack *cstack)
{
	t_cstack_ptrs	*start;
	t_cstack_ptrs	*stack;
	int				p_dist;
	int				n_dist;

	stack = cstack->stack;
	start = stack;
	p_dist = 0;
	while (stack != element)
	{
		stack = stack->next;
		p_dist++;
	}
	n_dist = cstack->size - p_dist;
	return ((p_dist <= n_dist) * p_dist + (p_dist > n_dist) * n_dist * -1);
}

int	distance_from_pos(int num, t_cstack *cstack)
{
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	while (!((num > stack->num && num < stack->previous->num)
			|| (num > stack->num && num > cstack->max) || (num < stack->num
				&& num < cstack->min)))
		stack = stack->next;
	return (distance_from_top(stack, cstack));
}

#define PP 0
#define PN 1
#define NP 2
#define NN 3

int	spin_optimiser(int ap, int an, int bp, int bn)
{
	// decides which spin to do
}

void	spin(t_cstack *stack_a, t_cstack *stack_b, int a_rot, int b_rot)
{
	// do the actual spinning and writting maybe
}

void	sort(t_cstack *stack_a)
{
	t_cstack	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_cstack));
	pop_push(stack_a, stack_b);
	pop_push(stack_a, stack_b);
	pop_push(stack_a, stack_b);
	update_min_max(stack_b);
	swap_top2(stack_b);
}
