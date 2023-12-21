/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:27:55 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:45:00 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	set_rotate_func(struct s_rotate_func *rf, int *rot)
{
	if (rot[_SRC] >= 0)
		rf->a_func = &rotate;
	else
		rf->a_func = &rotate_reverse;
	if (rot[_DST] >= 0)
		rf->b_func = &rotate;
	else
		rf->b_func = &rotate_reverse;
	if (rot[_SRC] >= 0 && rot[_DST] >= 0)
		rf->both_func = &rotate_both;
	else if (rot[_SRC] < 0 && rot[_DST] < 0)
		rf->both_func = &rotate_reverse_both;
	else
		rf->both_func = NULL;
}

void	apply_spin(struct s_rotate_func *rf, int *rot, struct s_stack_pair *sp)
{
	int	ad;
	int	bd;

	ad = (rf->a_func == &rotate) * -1 + (rf->a_func == &rotate_reverse) * 1;
	bd = (rf->b_func == &rotate) * -1 + (rf->b_func == &rotate_reverse) * 1;
	while (rot[_SRC] != 0 && rot[_DST] != 0 && rf->both_func != NULL)
	{
		rf->both_func(sp->stack_a, sp->stack_b);
		rot[_SRC] += ad;
		rot[_DST] += bd;
	}
	while (rot[_SRC] != 0)
	{
		rf->a_func(sp->stack_a);
		rot[_SRC] += ad;
	}
	while (rot[_DST] != 0)
	{
		rf->b_func(sp->stack_b);
		rot[_DST] += bd;
	}
}

void	spin(struct s_stack_pair *sp, int *rot)
{
	struct s_rotate_func	rf;

	set_rotate_func(&rf, rot);
	apply_spin(&rf, rot, sp);
	pop_push(sp->stack_a, sp->stack_b);
}

void	last_spin(t_cstack *cstack)
{
	int	spin;
	int	spin_dir;

	spin = distance_from_top(cstack->min, cstack);
	spin_dir = 1;
	if (spin > 0)
		spin_dir = -1;
	while (spin != 0)
	{
		if (spin > 0)
			rotate(cstack);
		if (spin < 0)
			rotate_reverse(cstack);
		spin += spin_dir;
	}
}
