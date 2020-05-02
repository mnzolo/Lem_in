/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:43:10 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/02/09 16:09:29 by mnzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant	*make(char **line, t_ant **head)
{
	t_ant *return_node;

	return_node = (t_ant *)malloc(sizeof(t_ant));
	return_node->line = (*line);
	return_node->next = NULL;
	if (!(*head))
		(*head) = return_node;
	return (return_node);
}

int				validator(char *liner, int comp, int c, int v, int r)
{
	if (c == 2 || v == 2)
		return (1);
	if (!max(liner))
		return (1);
	if (ft_strchr(liner,'-') && r == 0)
		return (1);
	if (ft_atol(liner) == 0 && comp == 0 && ft_strlen(liner) == 1)
		return (1);
	else
		return (0);
}

t_ant			*line(void)
{
	t_check x;

	x.c = 0;
	x.v = 0;
	x.r = 0;
	x.comp = 0;
	x.line = NULL;
	x.head = NULL;
	while (get_next_line(0, &x.line) == 1)
	{
		(ft_strstr(x.line, "##start")) ? x.v++ : 0;
		(ft_strstr(x.line, "##end")) ? x.c++ : 0;
		(validator(x.line, x.comp, x.c, x.v, x.r) == 1) ? no() : 0;
		if(x.r == 0)
			x.line = ft_strtrimer(x.line);
		if(ft_strchr(x.line,'+') && x.r == 0)
				no();
		if (!x.head)
			x.run = make(&x.line, &x.head);
		else
		{
			x.run->next = make(&x.line, &x.head);
			x.run = x.run->next;
		}
		(!ft_strchr(x.line, '-') && !ft_strchr(x.line, '#') &&
		ft_strchr(x.line, ' ')) ? x.comp++ : 0;
		x.line = NULL;
		x.r++;
	}
	(x.head ? x.head->max = x.comp : no());
	(x.line ? free(x.line) : 0);
	return (x.head);
}

static void		set_names(t_map *head, t_ant *lines)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = ft_atoi(lines->line);
	while (lines && head)
	{
		if (ft_strstr(lines->line, "##start"))
		{
			head->start = 1;
			head->ants = i;
		}
		if (ft_strstr(lines->line, "##end"))
			head->end = 1;
		if (ft_strchr(lines->line, ' ') && !ft_strchr(lines->line, '#'))
		{
			head->name = ft_strdup(lines->line);
			temp = ft_strchr(head->name, ' ');
			temp[0] = '\0';
			head = head->next;
		}
		lines = lines->next;
	}
}

t_map			*nodes(t_ant *lines)
{
	int		i;
	t_map	*run;
	t_map	*head;
	t_map	*temp;

	run = NULL;
	head = NULL;
	i = lines->max;
	while (--i >= 0)
	{
		temp = (t_map *)malloc(sizeof(t_map));
		temp->start = 0;
		temp->end = 0;
		temp->next = NULL;
		if (!head)
			head = temp;
		else
			run->next = temp;
		run = temp;
	}
	set_names(head, lines);
	return (head);
}
