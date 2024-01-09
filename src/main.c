/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:09:40 by bplante           #+#    #+#             */
/*   Updated: 2024/01/09 16:21:20 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_cstack *cstack)
{
	t_cstack_ptrs	*stack;

	stack = cstack->stack;
	while (true)
	{
		if (stack->num > stack->next->num && stack->next != cstack->stack)
			return (false);
		stack = stack->next;
		if (stack == cstack->stack)
			break ;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_cstack	*cstack;

	if (argc == 1)
		return (1);
	cstack = parse_inputs(&argv[1]);
	if (cstack == NULL)
	{
		ft_printf_fd("Error\n", 2);
		return (1);
	}
	if (!is_sorted(cstack))
		sort(cstack);
	cstack_clear(cstack);
	free(cstack);
}
