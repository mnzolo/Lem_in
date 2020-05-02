/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:44:05 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/02/10 09:38:01 by mnzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"

typedef	struct		s_map
{
	int				end;
	int				start;
	int				ants;
	int				best;
	char			*name;
	struct s_move	**moves;
	struct s_map	**tree;
	struct s_map	*next;
}					t_map;

typedef struct		s_move
{
	int				ants;
	int				exit;
	int				route_name;
	int				num_move;
	struct s_map	*pre;
	struct s_map	*home;
	struct s_move	*next;
}					t_move;

typedef struct		s_ants
{
	int				name;
	struct s_move	*home;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_ant
{
	int				max;
	char			*line;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_valid
{
	int				comp;
	int				c;
	int				v;
	int				r;
	char			*line;
	t_ant			*head;
	t_ant			*run;
}					t_check;

void				no(void);
long				ft_atol(const char *str);
char				*ft_strtrimer(char const *s);
int					max(char *str);
void				find_end(t_map *map);
t_ant				*line(void);
int					valid(t_ant *lines);
void				free_lines(t_ant **lines);
t_map				*nodes(t_ant *line);
void				free_dead_end(t_move **node);
void				free_map(t_map **map);
void				map(t_map *head, t_ant *lines);
void				freeq(t_ants **antq);
void				move(t_ants *antq, t_move *route);
void				init_ants(t_ant *lines, t_ants **q_ant);
t_move				*initiate_move(t_map *home, t_map *pre, int route, int\
		moves);
#endif
