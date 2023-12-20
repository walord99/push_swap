/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:05 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/20 00:10:00 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct			stack_pair
{
	t_cstack	*stack_a;
	t_cstack	*stack_b;
};

#define _src 0
#define _dst 1

static void		spin(struct stack_pair *sp, int *rot);
static int		count_move_to_pos(struct stack_pair *sp,
					t_cstack_ptrs *element);

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
	// while (!((num > stack->num && num < stack->previous->num)
	// 		|| (num > stack->num && num > cstack->max
	// 			&& stack->num == cstack->min) || (num < stack->num
	// 			&& num < cstack->min && stack->num == cstack->max)))
	// 	stack = stack->next;
	while (true)
	{
		if (num > stack->num && num < stack->previous->num)
			break ;
		if (num > stack->num && num > cstack->max && stack->previous->num == cstack->min)
			break ;
		if (num < stack->num && num < cstack->min && stack->num == cstack->max)
			break ;
		stack = stack->next;
	}
	return (distance_from_top(stack, cstack));
}

void	get_move_info(int *pos, bool *ambi, struct stack_pair *sp,
		t_cstack_ptrs *element)
{
	pos[_src] = distance_from_top(element, sp->stack_a);
	pos[_dst] = distance_from_pos(element->num, sp->stack_b);
	ambi[_src] = abs(pos[_src]) == sp->stack_a->size / 2 && sp->stack_a->size
		% 2 == 0;
	ambi[_dst] = abs(pos[_dst]) == sp->stack_b->size / 2 && sp->stack_b->size
		% 2 == 0;
}

void	spin_direction_optimiser(int *rot, int *pos, bool *ambi)
{
	if (ambi[_src] && ambi[_dst])
	{
		rot[_src] = pos[_src];
		rot[_dst] = pos[_dst];
	}
	else if (ambi[_src] && !ambi[_dst])
	{
		rot[_src] = (pos[_src] * -1) * (pos[_dst] <= 0) + pos[_src]
			* (pos[_dst] > 0);
		rot[_dst] = pos[_dst];
	}
	else if (!ambi[_src] && ambi[_dst])
	{
		rot[_src] = pos[_src];
		rot[_dst] = (pos[_dst] * -1) * (pos[_src] <= 0) + pos[_dst]
			* (pos[_src] > 0);
	}
	else
	{
		rot[_src] = pos[_src];
		rot[_dst] = pos[_dst];
	}
}

void	find_moves(struct stack_pair *sp, t_cstack_ptrs *element)
{
	int		rot[2];
	bool	ambi[2];
	int		pos[2];

	get_move_info(pos, ambi, sp, element);
	spin_direction_optimiser(rot, pos, ambi);
	spin(sp, rot);
}

t_cstack_ptrs	*find_least_move(struct stack_pair *sp)
{
	int				min;
	t_cstack_ptrs	*least_elem;
	t_cstack_ptrs	*stack;
	t_cstack_ptrs	*stack_start;

	min = INT_MAX;
	least_elem = NULL;
	stack = sp->stack_a->stack;
	stack_start = stack;
	min = count_move_to_pos(sp, stack);
	least_elem = stack;
	stack = stack->next;
	while (stack != stack_start)
	{
		if (count_move_to_pos(sp, stack) < min)
		{
			min = count_move_to_pos(sp, stack);
			least_elem = stack;
		}
		stack = stack->next;
	}
	return (stack);
}

int	count_move_to_pos(struct stack_pair *sp, t_cstack_ptrs *element)
{
	int		ret;
	int		pos[2];
	bool	ambi[2];

	get_move_info(pos, ambi, sp, element);
	if (ambi[_src] && ambi[_dst])
		ret = (pos[_src] >= pos[_dst]) * pos[_src] + (pos[_dst] > pos[_src])
			* pos[_dst];
	else if (ambi[_src] && !ambi[_dst])
		ret = (pos[_src] >= abs(pos[_dst])) * pos[_src]
			+ (abs(pos[_dst]) > pos[_src]) * abs(pos[_dst]);
	else if (!ambi[_src] && ambi[_dst])
		ret = (abs(pos[_src]) >= pos[_dst]) * abs(pos[_src])
			+ (pos[_dst] > abs(pos[_src])) * pos[_dst];
	else if ((pos[_src] > 0 && pos[_dst] > 0) || (pos[_src] < 0
			&& pos[_dst] < 0))
		ret = (abs(pos[_src]) >= abs(pos[_dst])) * abs(pos[_src])
			+ (abs(pos[_dst]) > abs(pos[_src])) * abs(pos[_dst]);
	else
		ret = abs(pos[_src]) + abs(pos[_dst]);
	return (ret + 1);
}

struct			rotate_func
{
	void		(*a_func)(t_cstack *);
	void		(*b_func)(t_cstack *);
	void		(*both_func)(t_cstack *, t_cstack *);
};

void	set_rotate_func(struct rotate_func *rf, int *rot)
{
	if (rot[_src] >= 0)
		rf->a_func = &rotate;
	else
		rf->a_func = &rotate_reverse;
	if (rot[_dst] >= 0)
		rf->b_func = &rotate;
	else
		rf->b_func = &rotate_reverse;
	if (rot[_src] >= 0 && rot[_dst] >= 0)
		rf->both_func = &rotate_both;
	else if (rot[_src] < 0 && rot[_dst] < 0)
		rf->both_func = &rotate_reverse_both;
	else
		rf->both_func = NULL;
}

void	apply_spin(struct rotate_func *rf, int *rot, struct stack_pair *sp)
{
	int	ad;
	int	bd;
	int	both_d;

	ad = (rf->a_func == &rotate) * -1 + (rf->a_func == &rotate_reverse) * 1;
	bd = (rf->b_func == &rotate) * -1 + (rf->b_func == &rotate_reverse) * 1;
	while (rot[_src] != 0 && rot[_dst] != 0 && rf->both_func != NULL)
	{
		rf->both_func(sp->stack_a, sp->stack_b);
		rot[_src] += ad;
		rot[_dst] += bd;
	}
	while (rot[_src] != 0)
	{
		rf->a_func(sp->stack_a);
		rot[_src] += ad;
	}
	while (rot[_dst] != 0)
	{
		rf->b_func(sp->stack_b);
		rot[_dst] += bd;
	}
}

void	spin(struct stack_pair *sp, int *rot)
{
	struct rotate_func	rf;

	set_rotate_func(&rf, rot);
	apply_spin(&rf, rot, sp);
	pop_push(sp->stack_a, sp->stack_b);
}

void	sort(t_cstack *stack_a)
{
	struct stack_pair	sp;
	t_cstack_ptrs		*least;

	sp.stack_a = stack_a;
	sp.stack_b = ft_calloc(1, sizeof(t_cstack));
	sp.stack_b->name = 'b';
	pop_push(sp.stack_a, sp.stack_b);
	pop_push(sp.stack_a, sp.stack_b);
	update_min_max(sp.stack_b);
			ft_printf("<------>\n");
	while (sp.stack_a->size > 3)
	{
		least = find_least_move(&sp);
		find_moves(&sp, least);
		ft_printf("<------>\n");
	}
}
