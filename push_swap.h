/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:46:38 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/26 16:04:38 by oduran-m         ###   ########.fr       */
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

#endif
