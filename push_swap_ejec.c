/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ejec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:18:44 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/06 21:48:45 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	int_len(long n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	put_long_in_str(long n, char *s, int *i)
{
	if (n >= 10)
		put_long_in_str(n / 10, s, i);
	s[(*i)++] = (char)('0' + (n % 10));
}

char	*double_to_str2(double nb)
{
	long	whole;
	long	dec;
	int		len;
	int		i;
	char	*s;

	whole = (long)nb;
	dec = (long)((nb - whole) * 100.0 + 0.5);
	if (dec == 100)
	{
		whole++;
		dec = 0;
	}
	len = int_len(whole) + 1 + 2 + 1;
	s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	i = 0;
	put_long_in_str(whole, s, &i);
	s[i++] = '.';
	if (dec < 10)
		s[i++] = '0';
	put_long_in_str(dec, s, &i);
	s[i] = '\0';
	return (s);
}

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

void	benchmark(t_flag *flags, t_datacount *data, double disorder)
{
	char	*str_dis;

	str_dis = double_to_str2(disorder);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putstr_fd(str_dis, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(method_name(flags->method), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(data->total_operations, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(data->sa, 2);
	ft_putstr_fd(" sb: ", 2);
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
	
	disorder = disorder_index(*a) * 100;	
	stack_b = NULL;
	init_datacount(&datacount);
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
