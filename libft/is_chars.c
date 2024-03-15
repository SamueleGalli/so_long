/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:43 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 11:57:13 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ritorna 1 se <c> e nella tavola ascii e 0 se non lo e
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

//ritorna 1 se <c> e stampabile e 0 se non lo e
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '-')
		return (1);
	return (0);
}

//ritorna 1 se <c> e considerato spazio e 0 se non lo e
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

//ritorna 1 se <c> e un numero e 0 se non lo e
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

//ritorna 1 se <c> e alphanumerico e 0 se non lo e
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}
