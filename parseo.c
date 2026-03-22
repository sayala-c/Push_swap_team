/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:33:45 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/22 18:12:50 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_flag(t_flag *flags)
{
	flags->method = METHOD_NONE;
	flags->bench = 0;
	flags->error = 0;
}
int	flags(t_flag *opts, char *argv)
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
	int	i;
	
	flag = 0;
	i = 0;
	while (argv[++i])
		if (!ft_strncmp(argv[i], "--", 2))
			flag += flags(argv[i]);
	else
		return (0);
}
