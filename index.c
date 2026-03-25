/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:05:09 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/25 17:57:56 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
float	disorder_index(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	float	pairs;
	float	mistakes;
	
	pairs = 0;
	mistakes = 0;
	i = a;
	if (a == NULL || a->next == NULL)
		return (0);
	while (i != NULL && i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes/pairs)
}


