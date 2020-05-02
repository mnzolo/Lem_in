/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:36:02 by tmuzeren          #+#    #+#             */
/*   Updated: 2020/01/31 15:36:22 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_c(char const *str, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (str == NULL)
		return (0);
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != c)
			word++;
		if (str[i] != c && str[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}
