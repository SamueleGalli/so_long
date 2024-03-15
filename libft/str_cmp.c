/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:55 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/11 10:45:47 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*compara non piu di <n> caratteri di <str1> e <str2>
ritorna la differenza ( *str1 - str2) tra i primi caratteri differenti
0 se non ci sono differenze*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 != '\0' && *str2 != '\0' && n--)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	if (n != 0 && (*str1 == '\0' || *str2 == '\0'))
		return ((unsigned char)*str1 - (unsigned char)*str2);
	return (0);
}

//ritorna 1 se <name> finisce in <extension> altrimenti 0
int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name = name + name_len - ext_len;
	while (*name != '\0')
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

//ritorna un puntatore al primo carattere della prima apparizione
//di <little> in <big>
//se <little> e una stringa vuota, ritorna <big>
//se <big> non include <little>, NULL e ritornato
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i] != '\0' && len - i > 0)
			{
				if (little[i] != big[i])
					break ;
				i++;
			}
			if (little[i] == '\0')
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
