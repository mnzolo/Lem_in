/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:34:44 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:34:46 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# include <unistd.h>

int			get_next_line(const int fd, char **line);

#endif
