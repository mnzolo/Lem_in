/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:54:40 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 14:55:08 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digit_count(int n)
{
//	int	remainder;
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n > 0 || n < 0)
	{
//		remainder = n % 10;
		n = n / 10;
		i++;
	}
	return (i);
}
