/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:10:27 by bplante           #+#    #+#             */
/*   Updated: 2023/12/18 13:57:59 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_cstack_ptrs
{
	struct s_cstack	*previous;
	int				num;
	struct s_cstack	*next;
}					t_cstack_ptrs;

typedef struct s_cstack
{
	int				size;
	t_cstack_ptrs	*stack;
}					t_cstack;

void				cstack_clear(t_cstack *cstack);
t_cstack			*cstack_add(t_cstack *cstack, int num);
int					cstack_size(t_cstack *cstack);

t_cstack			*parse_inputs(char **args);
void				rotate(t_cstack **stack);
void				rotate_reverse(t_cstack **stack);
void				pop_push(t_cstack **src, t_cstack **dest);
void				swap_top2(t_cstack **stack);

int					rotate_reverse(t_cstack **stack);
int					rotate(t_cstack **stack);
int					pop_push(t_cstack **src, t_cstack **dest, int *size_a,
						int *size_b);
int					swap_top2(t_cstack **stack);

#endif