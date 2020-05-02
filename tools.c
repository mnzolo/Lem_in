/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:32:09 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 12:33:22 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_dead_end(t_move **node)
{
	if ((*node)->next)
		free_dead_end(&(*node)->next);
	free((*node));
}

void	free_lines(t_ant **lines)
{
	if ((*lines)->next)
		free_lines(&(*lines)->next);
	free((*lines)->line);
	free((*lines));
}

void	free_map(t_map **map)
{
	int i;

	i = -1;
	if ((*map)->next)
		free_map(&(*map)->next);
	while ((*map)->moves && (*map)->tree[++i])
		free_dead_end(&(*map)->moves[i]);
	free((*map)->moves);
	free((*map)->tree);
	free((*map)->name);
	free((*map));
}

void	freeq(t_ants **antq)
{
	if ((*antq)->next)
		freeq(&(*antq)->next);
	free((*antq));
}

t_move	*initiate_move(t_map *home, t_map *pre, int route, int moves)
{
	t_move	*temp;

	temp = (t_move *)malloc(sizeof(t_move));
	temp->exit = 0;
	temp->pre = pre;
	temp->home = home;
	temp->num_move = moves;
	temp->route_name = route;
	temp->next = NULL;
	return (temp);
}
