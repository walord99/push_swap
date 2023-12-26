/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:54:01 by val               #+#    #+#             */
/*   Updated: 2023/12/26 02:54:23 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_command(char *str, t_cstack *stack_a, t_cstack *stack_b)
{
	if (!ft_strcmp(str, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(str, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(str, "rr"))
		rotate_both(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra"))
		rotate_reverse(stack_a);
	else if (!ft_strcmp(str, "rrb"))
		rotate_reverse(stack_b);
	else if (!ft_strcmp(str, "rrr"))
		rotate_reverse_both(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa"))
		pop_push(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb"))
		pop_push(stack_a, stack_b);
	else if (!ft_strcmp(str, "sa"))
		swap_top2(stack_a);
	else if (!ft_strcmp(str, "sb"))
		swap_top2(stack_b);
	else
		ft_printf_fd("Error\n", 2);
	free(str);
}

bool	is_sorted(t_cstack *cstack)
{
	t_cstack_ptrs	*stack;

	if (cstack->size == 0)
		return (false);
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

void	clear_stacks(t_cstack *stack_a, t_cstack *stack_b)
{
	if (stack_a->size != 0)
		cstack_clear(stack_a);
	if (stack_b->size != 0)
		cstack_clear(stack_b);
	free(stack_a);
	free(stack_b);
}

t_cstack	*init_cstack(void)
{
	return (ft_calloc(1, sizeof(t_cstack)));
}

int	main(int argc, char **argv)
{
	t_cstack	*cstack_a;
	char		*line;
	t_cstack	*cstack_b;

	if (argc < 2)
		return (1);
	cstack_a = parse_inputs(&argv[1]);
	if (cstack_a == NULL)
	{
		ft_printf_fd("Error\n", 2);
		return (1);
	}
	cstack_b = init_cstack();
	while (true)
	{
		line = get_next_line(0, 0);
		if (line == NULL)
			break ;
		parse_command(line, cstack_a, cstack_b);
	}
	if (is_sorted(cstack_a))
		ft_printf("%s", "OK\n");
	else
		ft_printf("%s", "KO\n");
	clear_stacks(cstack_a, cstack_b);
}
