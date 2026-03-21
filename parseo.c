/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:33:45 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/21 19:05:32 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flags(const char *argv)
{
	if (!ft_strncmp(argv, "--simple", 8))
			return (1);
		else if (!ft_strncmp(argv, "--medium", 8))
			return (2);
		else if (!ft_strncmp(argv, "--complex", 9))
			return (3);
		else if (!ft_strncmp(argv, "--adaptive", 10))
			return (4);
		else if (!ft_strncmp(argv, "--bench", 7))
			return (5);
		else
			return (10);	
	return (0);
}

int	parseo(char **argv)
{
	int	flag;

	flag = 0;
	if (!ft_strncmp(argv[1], "--", 2))
			return (flags(argv[1]));
	else
		return (0);
}
