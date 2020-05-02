/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:18:21 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:18:29 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ss;
	char	*str;
	size_t	i;

	i = 0;
	ss = (char *)s;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		while (ss[i] != '\0')
		{
			str[i] = ss[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}
