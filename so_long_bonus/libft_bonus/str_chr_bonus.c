/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:02:39 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/03 15:40:03 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

//ritorna un puntatore alla PRIMA apparizione del carattere c
//nella stringa str, o NULL se il carattere non e trovato
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

//ritorna un puntatore all'ULTIMA apparizione del carattere c
//nell stringa str, o NULL se il carattere non e trovato
char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (*(str + len) == (char)c)
			return ((char *)str + len);
	}
	return (NULL);
}

//ritorna un puntatore alla PRIMA apparizione del carattere <str>
// che non e incluso un <set>
char	*ft_strdiffc(const char *str, const char *set)
{
	if (str != NULL && set != NULL)
	{
		while (*str)
		{
			if (ft_strchr(set, *str) == 0)
				return ((char *)str);
			str++;
		}
		if (ft_strchr(set, *str) == 0)
			return ((char *)str);
	}
	return (NULL);
}

//ritorna un puntatore all'ULTIMA apparizione di un carattere in <str>
//che non e incluso in <set>
char	*ft_strrdiffc(const char *str, const char *set)
{
	int	len;

	if (str != NULL && set != NULL)
	{
		len = ft_strlen(str);
		while (len >= 0)
		{
			if (ft_strchr(set, *(str + len)) == 0)
				return ((char *)str + len);
			len--;
		}
		if (ft_strchr(set, *str) == 0)
			return ((char *)str + len);
	}
	return (NULL);
}
