/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:46:28 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/01 18:52:11 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algo(t_stack **a, t_datacount *data)
{
	int top;
	int middle;
	int bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > middle && top < bottom)
		execute_operations(SA, a, NULL, data);
	else if (top > middle && middle > bottom)
	{
		execute_operations(SA, a, NULL, data);
		execute_operations(RRA, a, NULL, data);
	}
	else if (top > middle && middle < bottom)
		execute_operations(RA, a, NULL, data);
	else if (top < middle && middle > bottom && top < bottom)
	{
		execute_operations(SA, a, NULL, data);
		execute_operations(RA, a, NULL, data);
	}
	else if (top < middle && middle > bottom && top > bottom)
		execute_operations(RRA, a, NULL, data);	
}

void complex_algo(t_stack **a, t_stack **b)
{

}
