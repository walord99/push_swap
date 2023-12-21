/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/20 16:20:23 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		spin(struct s_stack_pair *sp, int *rot);
static int		count_move_to_pos(struct s_stack_pair *sp,
					t_cstack_ptrs *element);

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
	// while (!((num > stack->num && num < stack->previous->num)
	// 		|| (num > stack->num && num > cstack->max
	// 			&& stack->num == cstack->min) || (num < stack->num
	// 			&& num < cstack->min && stack->num == cstack->max)))
	// 	stack = stack->next;
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
	// while (!((num > stack->num && num < stack->previous->num)
	// 		|| (num > stack->num && num > cstack->max
	// 			&& stack->num == cstack->min) || (num < stack->num
	// 			&& num < cstack->min && stack->num == cstack->max)))
	// 	stack = stack->next;
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

void	find_moves(struct s_stack_pair *sp, t_cstack_ptrs *element,
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

t_cstack_ptrs	*find_least_move(struct s_stack_pair *sp)
{
	int				min;
	t_cstack_ptrs	*least_elem;
	t_cstack_ptrs	*stack;

	min = INT_MAX;
	least_elem = NULL;
	stack = sp->stack_a->stack;
	while (true)
	{
		if (count_move_to_pos(sp, stack) < min)
		{
			min = count_move_to_pos(sp, stack);
			least_elem = stack;
		}
		stack = stack->next;
		if (stack == sp->stack_a->stack)
			break ;
	}
	return (least_elem);
}

int	count_move_to_pos(struct s_stack_pair *sp, t_cstack_ptrs *element)
{
	int		ret;
	int		pos[2];
	bool	ambi[2];

	get_move_info_desc(pos, ambi, sp, element);
	if ((pos[_SRC] > 0 && pos[_DST] > 0) || (pos[_SRC] < 0 && pos[_DST] < 0))
		ret = (abs(pos[_SRC]) >= abs(pos[_DST])) * abs(pos[_SRC])
			+ (abs(pos[_DST]) > abs(pos[_SRC])) * abs(pos[_DST]);
	else if (ambi[_SRC] && !ambi[_DST])
		ret = (pos[_SRC] >= abs(pos[_DST])) * pos[_SRC]
			+ (abs(pos[_DST]) > pos[_SRC]) * abs(pos[_DST]);
	else if (!ambi[_SRC] && ambi[_DST])
		ret = (abs(pos[_SRC]) >= pos[_DST]) * abs(pos[_SRC])
			+ (pos[_DST] > abs(pos[_SRC])) * pos[_DST];
	else
		ret = abs(pos[_SRC]) + abs(pos[_DST]);
	return (ret + 1);
}

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
	int	both_d;

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

void	sort_small(t_cstack *cstack)
{
	t_cstack_ptrs	*stack;
	int				dist;

	update_min_max(cstack);
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
		update_min_max(sp.stack_b);
	while (sp.stack_a->size > 3)
	{
		least = find_least_move(&sp);
		find_moves(&sp, least, -1);
	}
	sort_small(sp.stack_a);
	swap_stack_pair(&sp);
	while (sp.stack_a->size != 0)
	{
		find_moves(&sp, sp.stack_a->stack, 1);
	}
	last_spin(sp.stack_b);
}
