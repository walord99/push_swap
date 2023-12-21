/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:31 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:25:41 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_from_top(t_cstack_ptrs *element, t_cstack *cstack)
{
	t_cstack_ptrs	*stack;
	int				p_dist;
	int				n_dist;

	stack = cstack->stack;
	p_dist = 0;
	while (stack != element)
	{
		stack = stack->next;
		p_dist++;
	}
	n_dist = cstack->size - p_dist;
	return ((p_dist <= n_dist) * p_dist + (p_dist > n_dist) * n_dist * -1);
}

int	distance_from_pos_desc(int num, t_cstack *cstack)
{
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	while (true)
	{
		if (num > stack->num && num < stack->previous->num)
			break ;
		if (num > stack->num && num > cstack->max->num
			&& stack->previous == cstack->min)
			break ;
		if (num < stack->num && num < cstack->min->num && stack == cstack->max)
			break ;
		stack = stack->next;
	}
	return (distance_from_top(stack, cstack));
}

int	distance_from_pos_asc(int num, t_cstack *cstack)
{
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	while (true)
	{
		if (num < stack->num && num > stack->previous->num)
			break ;
		if ((num > cstack->max->num || num < cstack->min->num)
			&& stack->previous == cstack->max)
			break ;
		stack = stack->next;
	}
	return (distance_from_top(stack, cstack));
}

void	get_move_info_asc(int *pos, bool *ambi, struct s_stack_pair *sp,
		t_cstack_ptrs *element)
{
	pos[_SRC] = 0;
	pos[_DST] = distance_from_pos_asc(element->num, sp->stack_b);
	ambi[_SRC] = false;
	ambi[_DST] = false;
}

void	get_move_info_desc(int *pos, bool *ambi, struct s_stack_pair *sp,
		t_cstack_ptrs *element)
{
	pos[_SRC] = distance_from_top(element, sp->stack_a);
	pos[_DST] = distance_from_pos_desc(element->num, sp->stack_b);
	ambi[_SRC] = abs(pos[_SRC]) == sp->stack_a->size / 2 && sp->stack_a->size
		% 2 == 0;
	ambi[_DST] = abs(pos[_DST]) == sp->stack_b->size / 2 && sp->stack_b->size
		% 2 == 0;
}
