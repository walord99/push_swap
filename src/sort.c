/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/19 12:59:12 by bplante/Wal      ###   ########.fr       */
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
	while (!(num > stack->num && num < stack->previous->num)
		|| (num > stack->num && num > cstack->max && stack->num == cstack->min)
		|| (num < stack->num && num < cstack->min && stack->num == cstack->max))
		stack = stack->next;
	return (distance_from_top(stack, cstack));
}

int	count_move_to_pos(t_cstack *src, t_cstack *dst, t_cstack_ptrs *element)
{
	int		top_d;
	int		pos_d;
	bool	ambi_a;
	bool	ambi_b;
	int		ret;

	top_d = distance_from_top(element, src);
	pos_d = distance_from_pos(element->num, dst);
	ambi_a = abs(top_d) == src->size / 2 && src->size % 2 == 0;
	ambi_b = abs(pos_d) == dst->size / 2 && dst->size % 2 == 0;
	if (ambi_a && ambi_b)
		ret = (top_d >= pos_d) * top_d + (pos_d > top_d) * pos_d;
	else if (ambi_a && !ambi_b)
		ret = (top_d >= abs(pos_d)) * top_d + (abs(pos_d) > top_d) * abs(pos_d);
	else if (!ambi_a && ambi_b)
		ret = (abs(top_d) >= pos_d) * abs(top_d) + (pos_d > abs(top_d)) * pos_d;
	else if ((top_d > 0 && pos_d > 0) || (top_d < 0 && pos_d < 0))
		ret = (abs(top_d) >= abs(pos_d)) * abs(top_d)
			+ (abs(pos_d) > abs(top_d)) * abs(pos_d);
	else
		ret = abs(top_d) + abs(pos_d);
	return (ret + 1);
}

void	spin(t_cstack *stack_a, t_cstack *stack_b, int a_rot, int b_rot)
{
	// do the actual spinning and writting maybe
}

void	sort(t_cstack *stack_a)
{
	t_cstack	*stack_b;
	int			test;

	stack_b = ft_calloc(1, sizeof(t_cstack));
	pop_push(stack_a, stack_b);
	pop_push(stack_a, stack_b);
	update_min_max(stack_b);
}
