/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:02:55 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/07 20:53:44 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_flag(t_flag *flags)
{
    flags->method = METHOD_NONE;
    flags->bench = 0;
    flags->error = 0;
}

int	push_back(t_stack **stack, int value)
{
	t_stack *node;
	t_stack *tmp;

	node = new_node(value);
	if (!node)
		return (0);
	if (*stack == NULL)
	{
		*stack = node;
		return (1);
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp ->next;
	tmp->next = node;
	return (1);
}

void init_datacount(t_datacount *data)
{
	ft_memset(data, 0, sizeof(t_datacount));
}
