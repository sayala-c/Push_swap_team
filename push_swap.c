/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:45:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/20 00:17:27 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (ft_printf("Error"), NULL);
	else if (argc = 2)
		parseosplit(argv[1]);
	else if (argc > 2)
		parseo(argv);
		
	ft_printf("argc: %d\nargv: %s\n", argc, argv[1]);
	return (0);
}
