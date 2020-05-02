/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:39:01 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 12:39:07 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_out(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

int		check_done(t_ants *antq)
{
	while (antq && antq->home && antq->home->pre->end)
		antq = antq->next;
	if (antq)
		return (1);
	return (0);
}

int		check_duplicates(t_ants *antq, t_move *route)
{
	int	i;

	i = 0;
	while (antq)
	{
		if (antq->home && antq->home == route && !route->pre->end)
			i++;
		antq = antq->next;
	}
	if (i > 0)
		return (0);
	return (1);
}

void	start_end(t_ants *ants, t_move *route)
{
	while (ants)
	{
		print_out(ants->name, route->pre->name);
		ft_putchar('\n');
		ants = ants->next;
	}
}

void	move(t_ants *antq, t_move *route)
{
	t_ants	*ants;

	if (!route->pre->end)
		while (check_done(antq))
		{
			ants = antq;
			while (ants)
			{
				if (!ants->home && check_duplicates(antq, route))
				{
					ants->home = route;
					print_out(ants->name, ants->home->pre->name);
				}
				else if (ants->home && ants->home->next && \
						check_duplicates(antq, ants->home->next))
				{
					ants->home = ants->home->next;
					print_out(ants->name, ants->home->pre->name);
				}
				ants = ants->next;
			}
			ft_putchar('\n');
		}
	else
		start_end(antq, route);
}
