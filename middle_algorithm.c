/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:40:57 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/05 16:11:50 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "push_swap.h"

int calculate_chunk_size(int size)
{
    if (size <= 100)
        return (size / 5);
    else
        return (size / 11);
}

void    chunks_sort(t_stack **a, t_stack **b, t_datacount *data)
{
    int low;
    int high;
    int chunk_size;

    low = 0;
    chunk_size = calculate_chunk_size(stack_size(*a));
    high = chunk_size - 1;

    while (*a)
    {
        if ((*a)->index >= low && (*a)->index <= high)
        {
            execute_operations(PB, a, b, data);
            if (stack_size(*b) == high + 1)
            {
                low += chunk_size;
                high += chunk_size;
            }
        }
        else
            execute_operations(RA, a, b, data);
    }
    return_to_a(a, b, data);
}
