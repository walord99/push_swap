/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:10:27 by bplante           #+#    #+#             */
/*   Updated: 2023/12/18 15:19:48 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_cstack_ptrs
{
	struct s_cstack_ptrs	*previous;
	int						num;
	struct s_cstack_ptrs	*next;
}							t_cstack_ptrs;

typedef struct s_cstack
{
	int						size;
	t_cstack_ptrs			*stack;
}							t_cstack;

void						cstack_clear(t_cstack *cstack);
void						cstack_add(t_cstack *cstack, int num);

t_cstack					*parse_inputs(char **args);

void						rotate_reverse(t_cstack *stack);
void						rotate(t_cstack *stack);
void						pop_push(t_cstack *src, t_cstack *dest);
void						swap_top2(t_cstack *stack);

void						sort(t_cstack *stack_a);

#endif