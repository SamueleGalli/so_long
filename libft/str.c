/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:36:45 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/09 10:57:02 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//ritorna quanti caratteri ci sono in <str>
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

//ritorna il numero di gruppi di caratteri in <str>
//separato da <c>
int	ft_wordcount(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != c && *str != '\0')
				str++;
		}
		else if (*str)
			str++;
	}
	return (count);
}

//copia <dstsize> - 1 un carattere da <src> a <dst>
//ritorna la lungezza della stringa che provi a creare
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (src == NULL)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

//aggiunge <src> alla fine di <dst>.
//<dst> e considerato di avere <dstsize> bytes
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	dst_i;
	size_t	src_i;

	dst_len = ft_strlen(dst);
	dst_i = dst_len;
	src_i = 0;
	if (dstsize < dst_len + 1)
		return (dstsize + ft_strlen(src));
	if (dstsize > dst_len + 1)
	{
		while (src[src_i] != '\0')
		{
			dst[dst_i] = src[src_i];
			dst_i++;
			src_i++;
			if (dst_i == dstsize - 1)
				break ;
		}
	}
	dst[dst_i] = '\0';
	return (dst_len + ft_strlen(src));
}
