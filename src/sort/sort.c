/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:43:08 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	spin_direction_optimiser(int *rot, int *pos, bool *ambi)
{
	if (ambi[_SRC] && ambi[_DST])
	{
		rot[_SRC] = pos[_SRC];
		rot[_DST] = pos[_DST];
	}
	else if (ambi[_SRC] && !ambi[_DST])
	{
		rot[_SRC] = (pos[_SRC] * -1) * (pos[_DST] <= 0) + pos[_SRC]
			* (pos[_DST] > 0);
		rot[_DST] = pos[_DST];
	}
	else if (!ambi[_SRC] && ambi[_DST])
	{
		rot[_SRC] = pos[_SRC];
		rot[_DST] = (pos[_DST] * -1) * (pos[_SRC] <= 0) + pos[_DST]
			* (pos[_SRC] > 0);
	}
	else
	{
		rot[_SRC] = pos[_SRC];
		rot[_DST] = pos[_DST];
	}
}

void	print_moves(struct s_stack_pair *sp, t_cstack_ptrs *element,
		int direction)
{
	int		rot[2];
	bool	ambi[2];
	int		pos[2];

	if (direction == -1)
		get_move_info_desc(pos, ambi, sp, element);
	if (direction == 1)
		get_move_info_asc(pos, ambi, sp, element);
	spin_direction_optimiser(rot, pos, ambi);
	spin(sp, rot);
}

void	sort_small(t_cstack *cstack)
{
	t_cstack_ptrs	*stack;
	int				dist;

	set_min_max(cstack);
	stack = cstack->stack;
	while (true)
	{
		if (stack->num > stack->next->num && stack->next != cstack->min)
		{
			swap_top2(cstack);
			break ;
		}
		stack = stack->next;
		if (stack == cstack->stack)
			break ;
	}
	while (stack != cstack->min)
		stack = stack->next;
	dist = distance_from_top(stack, cstack);
	if (dist > 0)
		rotate(cstack);
	if (dist < 0)
		rotate_reverse(cstack);
}

void	swap_stack_pair(struct s_stack_pair *sp)
{
	t_cstack	*temp;

	temp = sp->stack_a;
	sp->stack_a = sp->stack_b;
	sp->stack_b = temp;
}

void	sort(t_cstack *stack_a)
{
	struct s_stack_pair	sp;
	t_cstack_ptrs		*least;

	sp.stack_a = stack_a;
	sp.stack_b = ft_calloc(1, sizeof(t_cstack));
	sp.stack_b->name = 'b';
	if (stack_a->size > 3)
		pop_push(sp.stack_a, sp.stack_b);
	if (stack_a->size > 4)
		pop_push(sp.stack_a, sp.stack_b);
	if (sp.stack_b->size > 0)
		set_min_max(sp.stack_b);
	while (sp.stack_a->size > 3)
	{
		least = find_least_move(&sp);
		print_moves(&sp, least, -1);
	}
	sort_small(sp.stack_a);
	swap_stack_pair(&sp);
	while (sp.stack_a->size != 0)
	{
		print_moves(&sp, sp.stack_a->stack, 1);
	}
	last_spin(sp.stack_b);
	free(sp.stack_a);
}
