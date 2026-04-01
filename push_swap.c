/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:45:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/01 16:48:54 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_front(t_stack **stack, int value)
{
	t_stack *new;

	new = new_node(value);
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}
/*
static const char	*method_name(t_method m)
{
	if (m == METHOD_SIMPLE)
		return ("SIMPLE");
	if (m == METHOD_MEDIUM)
		return ("MEDIUM");
	if (m == METHOD_COMPLEX)
		return ("COMPLEX");
	if (m == METHOD_ADAPTIVE)
		return ("ADAPTIVE");
	return ("NONE");
}

void	print_flags(const t_flag *opts)
{
	ft_printf("method: %s\n", method_name(opts->method));
	ft_printf("bench : %d\n", opts->bench);
	ft_printf("error : %d\n", opts->error);
}
*/
int	main(int argc, char **argv)
{
	t_flag opts;
	t_stack *stack_a;

	init_flag(&opts);
	stack_a = NULL;
	if (argc <= 1)
		return (ft_printf("Error"));
	if (parseo(argc, argv, &opts, &stack_a))
		return (ft_printf("Error1\n"), 1);
	if(opts.error)
		return (ft_printf("Error\n"), 1);
	return (0);
}
