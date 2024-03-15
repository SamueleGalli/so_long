/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:14:23 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 11:25:50 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//scrive int <nbr> in esodecimale, con i caratteri afabetici minucoli
//basandosi sul fil descritto da fd
void	ft_puthex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}

//scrive int <nbr> in long esadecimale, con caratteri alfabetici in minuscolo
//basandosi sul file definito da <fd>
void	ft_putlonghex_fd(unsigned long nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putlonghex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), fd);
	}
	else
		ft_putchar_fd(*(base + nbr), fd);
}

//scrive int <nbr> in esadecimale, con caratteri alfabetici in maiuscolo
//basandosi sul file definito da <fd>
void	ft_putupperhex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_puthex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}
