/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_route.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:44:43 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 12:44:49 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_move	*last_node(t_move *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

int		repeat(t_map *map, t_move *pre_node, t_move *sender)
{
	while (pre_node != sender && pre_node->pre != map && map != pre_node->home)
		pre_node = pre_node->next;
	if (pre_node->pre == map || map == pre_node->home)
	{
		return (0);
	}
	return (1);
}

void	end_add(t_move **hold, t_move **save, int *num_moves, int temp_move)
{
	if ((*hold)->next->exit && (temp_move < *num_moves || *num_moves == -1))
	{
		(*hold)->exit = 1;
		*num_moves = temp_move;
		if ((*save))
			free_dead_end(save);
		(*save) = (*hold)->next;
	}
	else
		free_dead_end(&(*hold)->next);
}

int		running(t_map *map, t_move *pre_node)
{
	int		i;
	t_move	*hold;
	t_move	*small_move;
	int		temp_move;
	int		num_moves;

	i = -1;
	small_move = NULL;
	hold = last_node(pre_node);
	num_moves = -1;
	(map->end ? hold->exit = 1 : 0);
	while (!map->end && map->tree[++i] && !hold->exit)
		if (repeat(map->tree[i], pre_node, hold))
		{
			hold->next = initiate_move(pre_node->home, map->tree[i], i, -1);
			temp_move = running(map->tree[i], pre_node);
			end_add(&hold, &small_move, &num_moves, temp_move);
			hold->next = NULL;
		}
	hold->next = small_move;
	return (map->end ? 1 : ++num_moves);
}

void	find_end(t_map *map)
{
	int i;

	i = 0;
	while (map && !map->start)
		map = map->next;
	if (map && map->end)
	{
		map->moves = NULL;
		map = map->next;
	}
	if (!map)
		return ;
	while (map->tree[i])
		i++;
	map->moves = (t_move **)malloc(sizeof(t_move *) * (1 + i));
	map->moves[i] = NULL;
	i = -1;
	while (map->tree[++i])
	{
		map->moves[i] = initiate_move(map, map->tree[i], i, 0);
		map->moves[i]->num_move = running(map->tree[i], map->moves[i]);
		if (!map->moves[i]->exit)
			map->moves[i]->num_move = -1;
	}
}
