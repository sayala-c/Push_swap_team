/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:33:45 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/25 17:03:16 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_method(t_flag *opts, t_method m)
{
	if (opts->method != METHOD_NONE)
	{
		opts->error = 1;
		return (1);
	}
	opts->method = m;
	return (0);
}

int	parse_flag(t_flag *opts, char *argv)
{
	if (!ft_strncmp(argv, "--simple", 9) && argv[8] == '\0')
		return (set_method(opts, METHOD_SIMPLE));
	else if (!ft_strncmp(argv, "--medium", 9) && argv[8] == '\0')
		return (set_method(opts, METHOD_MEDIUM));
	else if (!ft_strncmp(argv, "--complex", 10) && argv[9] == '\0')
		return (set_method(opts, METHOD_COMPLEX));
	else if (!ft_strncmp(argv, "--adaptive", 11) && argv[10] == '\0')
		return (set_method(opts, METHOD_ADAPTIVE));
	else if (!ft_strncmp(argv, "--bench", 8) && argv[7] == '\0')
	{
		if (opts->bench == 1)
			return (opts->error = 1, 1);
		opts->bench = 1;
		return (0);
	}
	opts->error = 1;
	return (1);
}

int	parseo(int argc, char **argv, t_flag *opts)
{
	int	i;
	
	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "--", 2))
		{
			if (parse_flag(opts, argv[i]) != 0)
				return (1);
			if (opts->error)
				return (1);
		}
	}
	if (opts->method == METHOD_NONE)
		opts->method = METHOD_ADAPTIVE;
	return (0);
}
