/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:20:48 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:20:50 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(dest);
	if (len > n)
		return (ft_strlen(src) + n);
	if (len < n)
		ft_strncat(dest, src, n - (len + 1));
	return (ft_strlen(src) + len);
}
