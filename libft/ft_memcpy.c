/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:08:58 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:09:00 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*de;
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	de = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (de == NULL && str == NULL)
		return ((unsigned char *)NULL);
	while (i < n)
	{
		de[i] = str[i];
		i++;
	}
	return (de);
}
