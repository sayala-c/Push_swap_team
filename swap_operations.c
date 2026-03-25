/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:34:17 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/25 20:47:04 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	swap_a(t_stack **a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*tmp;
	
	if (*a == NULL || (*a)->next == NULL)
        return (0);
	first_node = *a;
	second_node = (*a)->next;
	tmp = first_node;
	first_node->next = second_node->next; 
	second_node->next = tmp;
	*a = second_node;
	return (1);
}

int	swap_b(t_stack **b)
{
    t_stack *first_node;
    t_stack *second_node;
    t_stack *tmp;

    if (*b == NULL || (*b)->next == NULL)
        return (0);
    first_node = *b;
    second_node = (*b)->next;
    tmp = first_node;
    first_node->next = second_node->next;
    second_node->next = tmp;
    *b = second_node;
    return (1);
}

int	swap_ss(t_stack **a, t_stack **b)
{
	int call_a;
	int	call_b;

	call_a = swap_a(a);
	call_b = swap_b(b);
	if (call_a == 0 && call_b == 0)
		return(0);
	return(1);
}
