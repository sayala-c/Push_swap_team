/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:46:38 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/27 15:47:53 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft/libft.h"

typedef enum e_method
{
	METHOD_NONE = 0,
	METHOD_SIMPLE,
	METHOD_MEDIUM,
	METHOD_COMPLEX,
	METHOD_ADAPTIVE
} t_method;

typedef struct s_flag
{
	t_method	method;
	int			bench;
	int			error;
} t_flag;

typedef struct s_stack
{
	int			value;
	struct		s_stack  *next;
	int			index;
/*	int	pos;//posicion que esta actualmente en el stack (0,1,2)
	int	cost_a;//cuantos movimientos cuesta subir el nodo al tope de a 
	int	cost_b;//lo mismo pero con b, el qe tenga la suma mas baja es el que movemos
	int	target_pos//Si vas a mover un número del Stack A al Stack B, ¿en qué hueco exacto debe encajar para que B siga ordenado? y viceversa */
} t_stack

int	parseo(int argc, char **argv, t_flag *opts);
int	parse_flag(t_flag *opts, char *argv);
static int	set_method(t_flag *opts, t_method m);
double	disorder_index(t_stack *a);
void	print_flags(const t_flag *opts);
static const char	*method_name(t_method m);
void	push_front(t_stack **stack, int value);
t_stack	*new_node(int value);
void	init_flag(t_flag *flags);
int	push_a(t_stack **b, t_stack **a);
int	push_b(t_stack **a, t_stack **b);
int	rotate(t_stack **stack);
int	rotate_rr(t_stack **a, t_stack **b);
int	reverse_rotate(t_stack **stack);
int	rotate_rrr(t_stack **a, t_stack **b);
int	swap(t_stack **stack);
int	swap_ss(t_stack **a, t_stack **b);
#endif
