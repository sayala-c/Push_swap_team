/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:57:32 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/06 18:17:17 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a != NULL)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)//si tenemos 7 elementos (0 a 6) el 6 es el index maximo que podremos tener. Si 6 lo desplazamos x max_bits es = a nulo? No - sigue en bucle. (convierte el size en binario y va desplazando bites segun el max_bit hasta que quede en todo 0). Asi sabemos cuantas vueltas hay que dar, es decir cuántas veces tienes que repetir el proceso de mandar a B y devolver a A.
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				rotate(a);
			else
				push_b(a, b);
			j++;
		}
		while (stack_size(*b) != 0)
			push_a(a, b);
		i++;
	}
}
