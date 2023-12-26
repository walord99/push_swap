/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:09:49 by bplante           #+#    #+#             */
/*   Updated: 2023/12/26 03:01:57 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cstack_add(t_cstack *cstack, int num)
{
	t_cstack_ptrs	*new;
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	new = ft_calloc(1, sizeof(t_cstack_ptrs));
	new->num = num;
	if (!stack)
	{
		new->previous = new;
		new->next = new;
		stack = new;
	}
	if (stack->next == stack)
		link_new_1(stack, new);
	else
		link_new_gt1(stack, new);
	cstack->stack = stack;
	cstack->size++;
}

void	cstack_clear(t_cstack *cstack)
{
	t_cstack_ptrs	*start;
	t_cstack_ptrs	*temp;
	t_cstack_ptrs	*stack;

	if (cstack->stack == NULL)
		return ;
	stack = cstack->stack;
	start = stack;
	temp = stack;
	stack = stack->next;
	free(temp);
	while (stack != start)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
