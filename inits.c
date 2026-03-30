/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:02:55 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/30 21:39:21 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_flag(t_flag *flags)
{
    flags->method = METHOD_NONE;
    flags->bench = 0;
    flags->error = 0;
}

t_stack *new_node(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return (node);
}

void init_datacount(t_datacount *data)
{
	ft_memset(data, 0, sizeof(t_datacount));
}
