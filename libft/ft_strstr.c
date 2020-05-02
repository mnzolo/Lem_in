/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:31:36 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:31:39 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)hay + i);
		}
		i++;
	}
	return (0);
}
