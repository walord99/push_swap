/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:33:20 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/21 15:44:00 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap_struct.h"

void			get_move_info_asc(int *pos, bool *ambi, struct s_stack_pair *sp,
					t_cstack_ptrs *element);
void			get_move_info_desc(int *pos, bool *ambi,
					struct s_stack_pair *sp, t_cstack_ptrs *element);
int				distance_from_top(t_cstack_ptrs *element, t_cstack *cstack);

void			last_spin(t_cstack *cstack);
void			spin(struct s_stack_pair *sp, int *rot);
t_cstack_ptrs	*find_least_move(struct s_stack_pair *sp);

#endif