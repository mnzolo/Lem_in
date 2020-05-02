/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:28:25 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:28:29 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ss;
	char	*str;
	size_t	i;

	i = 0;
	ss = (char *)s1;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (ss[i] != '\0' && i < n)
	{
		str[i] = ss[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
