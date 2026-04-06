/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:45:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/06 21:16:21 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_flag		opts;
	t_stack		*stack_a;
	t_datacount	*data;

	init_flag(&opts);
	stack_a = NULL;
	if (argc <= 1)
		return (0);
	if (parseo(argc, argv, &opts, &stack_a))
		ft_printf("Error\n");
	value_index(&stack_a);
	init_datacount(&data);
	if (swap_ejecution(&stack_a, &opts))
		ft_printf("Error ejec\n");
		
	return (0);
}
