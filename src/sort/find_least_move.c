/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_least_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:29 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:41:07 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

int	count_total_move(struct s_stack_pair *sp, t_cstack_ptrs *element)
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
		if (count_total_move(sp, stack) < min)
		{
			min = count_total_move(sp, stack);
			least_elem = stack;
		}
		stack = stack->next;
		if (stack == sp->stack_a->stack)
			break ;
	}
	return (least_elem);
}
