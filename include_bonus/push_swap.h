/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:10:27 by bplante           #+#    #+#             */
/*   Updated: 2023/12/21 15:43:21 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_struct.h"
# include <libft.h>
# include <limits.h>

# define _SRC 0
# define _DST 1

void		cstack_clear(t_cstack *cstack);
void		cstack_add(t_cstack *cstack, int num);
void		set_min_max(t_cstack *cstack);

t_cstack	*parse_inputs(char **args);
int			is_valid_num(char *str);

void		rotate_reverse(t_cstack *stack);
void		rotate(t_cstack *stack);
void		rotate_both(t_cstack *stack_a, t_cstack *stack_b);
void		rotate_reverse_both(t_cstack *sa, t_cstack *sb);
void		pop_push(t_cstack *src, t_cstack *dest);
void		swap_top2(t_cstack *stack);

void		sort(t_cstack *stack_a);

void		link_new_to_top(t_cstack_ptrs *element, t_cstack *dest);
void		link_new_1(t_cstack_ptrs *stack, t_cstack_ptrs *new);
void		link_new_gt1(t_cstack_ptrs *stack, t_cstack_ptrs *new);

#endif