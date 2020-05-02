/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:34 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/02/09 15:46:23 by mnzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_end(t_map *head)
{
	int i;

	i = -1;
	while (head && !head->start)
		head = head->next;
	while (head->moves[++i])
		if (head->moves[i]->exit)
			return ;
	no();
}

void	comp(t_ant *line)
{
	while (line)
	{
		ft_putendl(line->line);
		line = line->next;
	}
	ft_putchar('\n');
}

void	mid_run(t_map *head, t_ants *antq)
{
	t_ants	*run;

	while (head && !head->start)
		head = head->next;
	run = antq;
	while (run)
	{
		run->home = NULL;
		run = run->next;
	}
	move(antq, head->moves[head->best]);
}

void	best_route(t_map *head, t_ants *antq)
{
	int i;
	int num_move;

	i = 0;
	head->best = 0;
	while (head && !head->start)
		head = head->next;
	if (head)
	{
		head->ants = 0;
		num_move = head->moves[i]->num_move;
		while (head->moves[++i])
			if (num_move > head->moves[i]->num_move || num_move == -1)
			{
				num_move = head->moves[i]->num_move;
				head->best = i;
			}
	}
	while (antq)
	{
		antq->home = head->moves[head->best];
		antq = antq->next;
	}
}

int		main(void)
{
	t_ant	*temp_ant;
	t_map	*head;
	t_ants	*antq;

	head = NULL;
	temp_ant = line();
	valid(temp_ant);
	head = nodes(temp_ant);
	map(head, temp_ant);
	init_ants(temp_ant, &antq);
	find_end(head);
	check_end(head);
	best_route(head, antq);
	comp(temp_ant);
	mid_run(head, antq);
	free_lines(&temp_ant);
	free_map(&head);
	freeq(&antq);
	return (0);
}
