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

void	sort_three(t_stack **a, t_datacount *data)
{
	int top;
	int middle;
	int bottom;

	top = (*a)->index;
	middle = (*a)->next->index;
	bottom = (*a)->next->next->index;
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

int	min_index_position(t_stack *a, int target_index)
{
	int	pos;

	pos = 0;
	while(a)
	{
		if (a->index == target_index)
			return (pos);
		a = a->next;
		pos++;
	}
	return (0);
}

void sort_four(t_stack **a, t_stack **b, t_datacount *data, int start_index)//, lepasamos start_index para optimizar sort_five ya que en asi podemos llamar a sort_four empezando por el segundo nodo mas paque, ya que en 5 el mas peque ya lo habremos pasado a b. Pones el mas peque en primera posicion y pasarso a b para usar el sort 3, ordenar los 3 que hay en el stack y pasar b al head de a
{
	int	pos;

	pos = min_index_position(*a, start_index);
	if (pos == 1)
		execute_operations(RA, a, b, data);
	else if (pos == 2)
	{
		execute_operations(RA, a, b, data);
		execute_operations(RA, a, b, data);
	}
	else if(pos == 3)
		execute_operations(RRA, a, b, data);
	execute_operations(PB, a, b, data);
	sort_three(a, data);
	execute_operations(PA, a, b, data);
}

void	sort_five(t_stack **a, t_stack **b, t_datacount *data)
{
	int	pos;

	pos = min_index_position(*a, 0);
	if (pos == 1)
		execute_operations(RA, a, b, data);
	else if (pos == 2)
	{
		execute_operations(RA, a, b, data);
		execute_operations(RA, a, b, data);
	}
	else if (pos == 3)
	{
		execute_operations(RRA, a, b, data);
		execute_operations(RRA, a, b, data);
	}
	else if (pos == 4)
		execute_operations(RRA, a, b, data);
	execute_operations(PB, a, b, data);
	sort_four(a, b, data, 1);
	execute_operations(PA, a, b, data);	
}
