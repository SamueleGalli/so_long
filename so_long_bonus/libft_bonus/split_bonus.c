/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:28:43 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 11:57:51 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static int	ft_lettercount(const char *str, char c)
{
	int	lcount;

	lcount = 0;
	while (str[lcount] != c && str[lcount] != '\0')
		lcount++;
	return (lcount);
}

//crea con malloc una tavola 2D e salva <str>
//diviso in stringe separate da <c>
char	**ft_split(const char *str, char c)
{
	char	**output;
	int		wordcount;
	int		wordindex;
	int		lettercount;

	if (str == NULL)
		return (NULL);
	wordcount = ft_wordcount(str, c);
	output = malloc(sizeof(char *) * wordcount + 1);
	if (output == NULL)
		return (NULL);
	wordindex = 0;
	while (wordindex < wordcount)
	{
		while (*str == c)
			str++;
		lettercount = ft_lettercount(str, c);
		output[wordindex] = ft_substr(str, 0, lettercount);
		if (output[wordindex] == NULL)
			return (NULL);
		str += lettercount;
		wordindex++;
	}
	output[wordindex] = NULL;
	return (output);
}
