/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:45:05 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 11:07:32 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_bonus.h"

//trasforma <n> bytes se <str> e in <c>
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*auxstr;
	int				i;

	i = 0;
	auxstr = (unsigned char *)str;
	while (i < (int)n)
	{
		auxstr[i] = c;
		i++;
	}
	return (str);
}

//trasforma <n> byte di <target in '\0'
void	ft_bzero(void *target, size_t n)
{
	ft_memset(target, '\0', n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*auxdest;
	char	*auxsrc;
	int		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	while (i < (int)n)
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, void *src, size_t len)
{
	void	*og;

	if (dest == NULL && src == NULL)
		return (NULL);
	og = dest;
	if (dest < src)
		ft_memcpy(dest, src, len);
	else
	{
		while (len--)
		{
			*((unsigned char *)dest + len) = *((unsigned char *)src + len);
		}
	}
	return (og);
}

/*copia byte da <src> a <dst>
se il carattere <c> appare in <src>, la copia si ferma
al ritorna il puntatore dopo il byte <c>
in <dest>. altrimenti <n> byte sono copiati
e un puntatore nullo e ritornatoi*/
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*auxdst;
	unsigned char	*auxsrc;
	int				i;

	auxdst = (unsigned char *)dst;
	auxsrc = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		auxdst[i] = auxsrc[i];
		if (auxsrc[i] == (unsigned char)c)
			return (&auxdst[i + 1]);
		i++;
	}
	return (NULL);
}
