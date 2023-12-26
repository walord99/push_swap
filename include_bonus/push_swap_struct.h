/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:33 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:42:08 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct s_cstack_ptrs
{
	struct s_cstack_ptrs	*previous;
	int						num;
	struct s_cstack_ptrs	*next;
}							t_cstack_ptrs;

typedef struct s_cstack
{
	t_cstack_ptrs			*min;
	t_cstack_ptrs			*max;
	int						size;
	t_cstack_ptrs			*stack;
	char					name;
}							t_cstack;

struct						s_stack_pair
{
	t_cstack				*stack_a;
	t_cstack				*stack_b;
};

struct						s_rotate_func
{
	void					(*a_func)(t_cstack *);
	void					(*b_func)(t_cstack *);
	void					(*both_func)(t_cstack *, t_cstack *);
};

#endif