/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:40:14 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/05 18:03:21 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)/*no hace falta hacer uno para a y otro para b
 xq son identicos y se les puede pasar en el main el stack que corresponde*/
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	return (1);
}

int	rotate_rr(t_stack **a, t_stack **b)
{
	int	rotate_a;
	int	rotate_b;

	if (stack_size(*a) < 2 || stack_size(*b) < 2)
		return (0);
	rotate_a = rotate(a);
	rotate_b = rotate(b);
	return (1);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack		*last;
	t_stack		*penultimate;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	penultimate = *stack;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rotate_rrr(t_stack **a, t_stack **b)
{
	int	rrr_a;
	int	rrr_b;

	rrr_a = reverse_rotate(a);
	rrr_b = reverse_rotate(b);
	if (rrr_a == 0 && rrr_b == 0)
		return (0);
	return (1);
}
