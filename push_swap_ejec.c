/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ejec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:18:44 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/06 19:23:56 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_ejecution(t_stack **a, t_flag *flags)
{
	t_stack		*stack_b;
	t_datacount	datacount;
	
	stack_b = NULL;
	if (disorder_index(*a) == 0)
		ft_printf("ordenado\n");
	else if (flags->method == METHOD_SIMPLE)
		ft_printf("method simple\n");
	else if (flags->method == METHOD_MEDIUM)
		ft_printf("method medium\n");
	else if (flags->method == METHOD_COMPLEX)
		radix_sort(a, &stack_b, &datacount);
	else if (flags->method == METHOD_ADAPTIVE)
		ft_printf("method adaptive\n");
	if (flags->bench == 1)
		ft_printf("benchmark\n");
		
	
	return (0);
}

void	value_index(t_stack **a)
{
	int	size;
	int	i;
	t_stack	 *min_node;
	t_stack	*current;
	
	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		current = *a;
		min_node = NULL;
		while (current != NULL)
		{
			if (current->index == -1  && (min_node == NULL || current->value < min_node->value))
				min_node = current;
			current = current->next;
		}
			if (min_node != NULL)
				min_node->index = i;
		i++;
	}
}
