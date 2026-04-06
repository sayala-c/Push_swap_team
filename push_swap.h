/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:46:38 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/06 17:27:20 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>

typedef enum e_method
{
	METHOD_NONE = 0,
	METHOD_SIMPLE,
	METHOD_MEDIUM,
	METHOD_COMPLEX,
	METHOD_ADAPTIVE
}	t_method;

typedef struct s_flag
{
	t_method	method;
	int			bench;
	int			error;
}	t_flag;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				index;
/*	int	pos;//posicion que esta actualmente en el stack (0,1,2)
	int	cost_a;//cuantos movimientos cuesta subir el nodo al tope de a 
	int	cost_b;//lo mismo pero con b, el qe tenga la
	 suma mas baja es el que movemos
	int	target_pos//Si vas a mover un número del Stack A al Stack B, 
	¿en qué hueco exacto debe encajar para que B siga ordenado? y viceversa */
}	t_stack;

typedef enum e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operations; /*IDs para los movimientos,on tipo de datos, 
no valiables no hayq que inicializarlo. el compilador le asigna un num 
permanente a cada ID (esa es su "inicializacion"), pero usaremos SA,
etc en vez el nuero para mejor lectura para nosotros. 
Este ID se le pasa a la funcion execute para que llame al 
movimiento que corresponda y o lo sume para bench o lo imprima en stout*/

typedef struct s_datacount
{
	int	bench_mode;//0 si no lo usamos y 1 si usamos --bench
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_operations;
}	t_datacount; // son variables, se inicializa poniendo todo a 0 en el inits.c

//Function Parseo
int		set_method(t_flag *opts, t_method m);
int		is_valid_int(char *str);
int		parseo(int argc, char **argv, t_flag *opts, t_stack **stack);
int		parse_flag(t_flag *opts, char *argv);
void	init_flag(t_flag *flags);
int		push_back(t_stack **stack, int value);
int		is_duplicate(t_stack *stack, int value);
//Function Algoritmo
double	disorder_index(t_stack *a);
t_stack	*new_node(int value);
void	execute_operations(t_operations operation,
			t_stack **a, t_stack **b, t_datacount *data);
void	show_operations(t_operations operation, t_datacount *data);
void	update_data_count(t_operations operation, t_datacount *data);
int		push_a(t_stack **b, t_stack **a);
int		push_b(t_stack **a, t_stack **b);
int		rotate(t_stack **stack);
int		rotate_rr(t_stack **a, t_stack **b);
int		reverse_rotate(t_stack **stack);
int		rotate_rrr(t_stack **a, t_stack **b);
int		swap(t_stack **stack);
int		swap_ss(t_stack **a, t_stack **b);
//Ejecution swap
int		swap_ejecution(t_stack **a, t_flag *flags);
void	value_index(t_stack **a);
int		stack_size(t_stack *a);
#endif
