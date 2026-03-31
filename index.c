/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:05:09 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/31 18:16:12 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
double	disorder_index(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	double	pairs;
	double	mistakes;
	
	pairs = 0;
	mistakes = 0;
	i = a;
	if (a == NULL || a->next == NULL)
		return (0);
	j = 0;
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

void  execute_operations(t_operations operation, t_stack *a, t_stack *b, t_datacount *data)
{
	if (operation == SA && swap(a) == 1)
		show_operations(operation, data);
	else if (operation == SB && swap(b) == 1)
		show_operations(operation, data);
	else if (operation == SS && swap_ss(a, b) == 1)
        show_operations(operation, data);
    else if (operation == PA && push_a(b, a) == 1)
        show_operations(operation, data);
    else if (operation == PB && push_b(a, b) == 1)
        show_operations(operation, data);
    else if (operation == RA && rotate(a) == 1)
        show_operations(operation, data);
    else if (operation == RB && rotate(b) == 1)
        show_operations(operation, data);
    else if (operation == RR && rotate_rr(a, b) == 1)
        show_operations(operation, data);
    else if (operation == RRA && reverse_rotate(a) == 1)
        show_operations(operation, data);
    else if (operation == RRB && reverse_rotate(b) == 1)
        show_operations(operation, data);
    else if (operation == RRR && rotate_rrr(a, b) == 1)
        show_operations(operation, data);
}
	
void show_operations(t_operations operation, t_datacount *data)
{
	static char *names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (data->bench_mode == 1)
		update_data_count(operation ,data);		
	else
	{
		ft_putstr_fd(names[operation], 1);
		write(1, "\n", 1);
	}
}

void update_data_count(t_operations operation, t_datacount *data)
{
	data->total_operations++;
	if (operation == SA)
		data->sa++;
	else if (operation == SB)
		data->sb++;
	else if (operation == SS)
        data->ss++;
    else if (operation == PA)
        data->pa++;
    else if (operation == PB)
        data->pb++;
    else if (operation == RA)
        data->ra++;
    else if (operation == RB)
        data->rb++;
    else if (operation == RR)
        data->rr++;
    else if (operation == RRA)
        data->rra++;
    else if (operation == RRB)
        data->rrb++;
    else if (operation == RRR)
        data->rrr++;
}
