/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:01:04 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/06 19:29:33 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptative_alg(t_stack **a, t_stack **b, t_datacount *data)
{
	int		size;
	double	disorder;

	size = stack_size(*a);
	if (size == 2)
		execute_operations(SA, a, b, data);
	else if (size == 3)
		sort_three(a, data);
	else if (size == 4)
		sort_four(a, b, data, 0);
	else if (size == 5)
		sort_five(a, b, data);
	else
	{	
		disorder = disorder_index(*a);
		/*if (disorder < 0.2)
			//simple_sort();
		else if (disorder >= 0.20 && disorder < 0.5)	
			 //medium_sort();
		else*/
		radix_sort(a, b, data);
	}
}
