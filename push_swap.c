/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:45:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/26 17:56:16 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_flag(t_flag *flags)
{
	flags->method = METHOD_NONE;
	flags->bench = 0;
	flags->error = 0;
}

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if(!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	push_front(t_stack **stack, int value)
{
	t_stack *new;

	new = new_node(value);
	if (!new)
		return (NULL);
	new->next = *stack;
	*stack = new;
}

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

int	main(int argc, char **argv)
{
	t_flag opts;

	init_flag(&opts);
	if (argc <= 1)
		return (ft_printf("Error"));
	if (parseo(argc, argv, &opts))
		return (ft_printf("Error\n"), 1);
	if(opts.error)
		return (ft_printf("Error\n"), 1);
	print_flags(&opts);	
	return (0);
}
