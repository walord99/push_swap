/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:09:40 by bplante           #+#    #+#             */
/*   Updated: 2023/12/06 18:05:00 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cstack	*cstack;

	if (argc < 2)
	{
		ft_printf_fd("Error\n", 2);
		return (1);
	}
	cstack = parse_inputs(&argv[1]);
}
