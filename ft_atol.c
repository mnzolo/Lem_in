/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnzolo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:47:36 by mnzolo            #+#    #+#             */
/*   Updated: 2020/02/09 15:55:36 by mnzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long		ft_atol(const char *str)
{
	long	i;
	long	neg;
	long	res;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\b' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-')
		neg = neg * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

int			max(char *str)
{
	long int	n;

	n = ft_atol(str);
	if (n < -2147483648 || n > 2147483647)
		return (0);
	if (ft_strlen(str) == ft_strlen("2147483647"))
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	return (1);
}

char	*ft_strtrimer(char const *s)
{
	size_t			i;
	unsigned int	start;
	unsigned int	len;
	char			*new;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ("");
	start = 0;
	len = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' ||
				s[start] == '\t' || s[start] == '+') && (start < ft_strlen(s)))
		start++;
	while ((s[len] == ' ' || s[len] == '\n' ||
				s[len] == '\t') && (len > start))
		len--;
	i = len - start + 1;
	new = ft_strsub(s, start, i);
	return (new);
}
