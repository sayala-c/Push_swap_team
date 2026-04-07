/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ejec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:18:44 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/07 20:07:49 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


char	*method_name(t_method m)
{
	if (m == METHOD_SIMPLE)
		return ("Simple / O(n2)");
	if (m == METHOD_MEDIUM)
		return ("Medium / O(n√n)");
	if (m == METHOD_COMPLEX)
		return ("Complex / O(n log n)");
	if (m == METHOD_ADAPTIVE)
		return ("Adaptive / O(n√n)");
	return ("NONE");
}

void	print_disorder(double disorder)
{
	int	num;
	int	dec;
	
	num = disorder;
	dec = (num - disorder) * 100 + 0.5;
	if (num == 100)
		return (ft_putstr_fd("100", 2));
	ft_putnbr_fd(num, 2);
	write(2, ".", 1);
	if (dec < 0)
		dec *= -1;
	if (dec == 0)
		return (ft_putstr_fd("00", 2));
	ft_putnbr_fd(dec, 2);
}

void	benchmark(t_flag *flags, t_datacount *data, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(disorder);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(method_name(flags->method), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(data->total_operations, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(data->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(data->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->rrr, 2);
	ft_putstr_fd("\n", 2);
}

int	swap_ejecution(t_stack **a, t_flag *flags)
{
	t_stack		*stack_b;
	t_datacount	datacount;
	double		disorder;
	
	disorder = disorder_index(*a) * 100;	
	stack_b = NULL;
	init_datacount(&datacount);
	datacount.bench_mode = flags->bench;
	if (disorder == 0)
		return (0);
	else if (flags->method == METHOD_SIMPLE)
		simple_sort(a, &stack_b, &datacount);
	else if (flags->method == METHOD_MEDIUM)
		ft_printf("method medium\n");
	else if (flags->method == METHOD_COMPLEX)
		radix_sort(a, &stack_b, &datacount);
	else if (flags->method == METHOD_ADAPTIVE)
		adaptative_alg(a, &stack_b, &datacount);
	if (flags->bench == 1 && disorder != 0)
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
