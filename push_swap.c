/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:45:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/21 18:48:27 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc <= 1)
		return (ft_printf("Error"));
	else if (argc == 2)
		flag =	parseo(argv); // 1-> con flag 10->no flag
		
	ft_printf("flag: %d\n", flag);
	return (0);
}
