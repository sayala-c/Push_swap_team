/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ejec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:18:44 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/06 20:11:33 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*method_name(t_method m)
{
	if (m == METHOD_SIMPLE)
		return ("Simple / O(n2)");
	if (m == METHOD_MEDIUM)
		return ("Medium / O(n√n)");
	if (m == METHOD_COMPLEX)
		return ("Complex / O(nlogn)");
	if (m == METHOD_ADAPTIVE)
		return ("Adaptive / O(n√n)");
	return ("NONE");
}

void	benchmark(t_flag *flags, t_datacount *data, double disorder)
{
	ft_printf("[bench] disorder: %d%%\n", disorder);
	ft_printf("[bench] strategy: %s\n", method_name(flags->method));
	ft_printf("[bench] total_ops: %d%%\n", data->total_operations);
	ft_printf("[bench] sa: %d ", data->sa);
	ft_printf("sb: %d ", data->sb);
	ft_printf("ss: %d ", data->ss);
	ft_printf("pa: %d ", data->pa);
	ft_printf("pb: %d \n", data->pb);
	ft_printf("[bench] ra: %d ", data->ra);
	ft_printf("rb: %d ", data->rb);
	ft_printf("rr: %d ", data->rr);
	ft_printf("rra: %d ", data->rra);
	ft_printf("rrb: %d ", data->rrb);
	ft_printf("rrr: %d \n", data->rrr);
}

int	swap_ejecution(t_stack **a, t_flag *flags)
{
	t_stack		*stack_b;
	t_datacount	datacount;
	double		disorder;
	
	disorder = disorder_index(*a);
	stack_b = NULL;
	if (disorder == 0)
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
		benchmark(flags, &datacount, disorder);
		
	
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
