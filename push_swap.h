/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:46:38 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/22 18:02:22 by oduran-m         ###   ########.fr       */
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
	METHOD_ADAPTIVE,
} t_method;

typedef struct s_flag
{
	t_method	method;
	int			bench;
	int			error;
} t_flag;

int	parseo(char **argv);

#endif
