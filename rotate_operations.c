/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:40:14 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/26 17:26:40 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rotate_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
        return (0);
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	return (1);
}

int	rotate_b(t_stack **b)
{

}
