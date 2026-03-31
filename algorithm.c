/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:46:28 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/31 19:37:44 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple(t_stack **a, t_datacount *data)
{
	int top;
	int middle;
	int bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
}
