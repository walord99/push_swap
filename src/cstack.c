/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:09:49 by bplante           #+#    #+#             */
/*   Updated: 2023/12/06 14:18:31 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cstack	*cstack_add(t_cstack *cstack, int num)
{
	t_cstack	*new;

	new = ft_calloc(1, sizeof(t_cstack));
	new->num = num;
	if (!cstack)
	{
		new->previous = new;
		new->next = new;
		return (new);
	}
	new->previous = cstack->previous;
	new->next = cstack;
	cstack->previous = new;
	return cstack;
}

void	cstack_clear(t_cstack *cstack)
{
	t_cstack *start;
	t_cstack *temp;
	start = cstack;
	while (cstack != start)
	{
		temp = cstack;
		cstack = cstack->next;
		free(temp);
	}
}
