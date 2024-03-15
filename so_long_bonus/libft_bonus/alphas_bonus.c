/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:52:39 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/22 16:01:52 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

// ritorna 1 se <c> e una lettera.0 se non lo e
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

//ritorna 1 se <c> e maiuscola.
//0 se e minuscola
// e -1 se non e una lettera
int	ft_isupperalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (0);
	return (-1);
}

//ritorna la lettera maiuscola
//e lo stesso carattere se non e minuscola
int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 'a')
		return (c - 32);
	return (c);
}

//ritorna la minuscola di una lettera
//e lo stesso carattere se non e maiuscola
int	ft_tolower(int c)
{
	if (ft_isalpha(c) && c <= 'Z')
		return (c + 32);
	return (c);
}
