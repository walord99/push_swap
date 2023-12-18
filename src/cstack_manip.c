/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:27:25 by bplante           #+#    #+#             */
/*   Updated: 2023/12/18 13:54:37 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top2(t_cstack **stack)
{
	if (stack[0] == stack[0]->next)
		return ;
	if (stack[0] == stack[0]->next->next)
		rotate(stack);
	else
	{
	}
}

void	pop_push(t_cstack **src, t_cstack **dest)
{
}

void	rotate(t_cstack **stack)
{
	*stack = stack[0]->next;
}

void	rotate_reverse(t_cstack **stack)
{
	*stack = stack[0]->previous;
}
