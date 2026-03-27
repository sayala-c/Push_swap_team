/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:34:17 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/27 18:25:57 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*tmp;
	
	if (*stack == NULL || (*stack)->next == NULL)
        return (0);
	first_node = *stack;
	second_node = (*stack)->next;
	tmp = first_node;
	first_node->next = second_node->next; 
	second_node->next = tmp;
	*stack = second_node;
	return (1);
}

int	swap_ss(t_stack **a, t_stack **b)
{
	int call_a;
	int	call_b;

	call_a = swap(a);
	call_b = swap(b);
	if (call_a == 0 && call_b == 0)
		return(0);
	return(1);
}

void print_sa(t_stack **a)
{
	int sa;

	sa = swap(a);
	if (sa == 1)
		write(1, "sa\n", 3);
}

void print_sb(t_stack **b)
{
	int	sb;
	
	sb = swap(b);
	if (sb == 1)
		write(1, "sb\n", 3);
}

void print_ss(t_stack **a, t_stack **b)
{
	int	ss;
	
	ss = swap_ss(a, b);
	if (ss == 1)
		write(1, "ss\n", 3);
}
