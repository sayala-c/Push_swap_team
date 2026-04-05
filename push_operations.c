/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:47:46 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/05 18:16:38 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack **b, t_stack **a)
{
	t_stack	*move_node;
	t_stack	*first_b;
	t_stack	*first_a;

	if (*b == NULL)
		return (0);
	first_a = *a;
	first_b = *b;
	move_node = first_b;
	*b = (*b)->next;
/*se necesita parentesis para cambiar el orden de lectura, 
lo normal es de derecha a izquierda, seria como pedirne, entra en b 
y buca next (b->next), b no es un nodo 
(es un puntero con la dir de mem de la variable b del main), 
asi que falla ya qque no hay un next y nunca lee *. 
Al poner (*b) cmbias el orden de lectura al parentesis primero, 
*b si es un nodo asi que puede acceder a next.*/
	move_node->next = first_a;
	*a = move_node;
	return (1);
}

int	push_b(t_stack **a, t_stack **b)
{
	t_stack	*move_node;
	t_stack	*first_b;
	t_stack	*first_a;

	if (*a == NULL)
		return (0);
	first_a = *a;
	first_b = *b;
	move_node = first_a;
	*a = (*a)->next;
	move_node->next = first_b;
	*b = move_node;
	return (1);
}
