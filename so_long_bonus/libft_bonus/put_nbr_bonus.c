/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:26:37 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 11:34:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static void	writenbr(long long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		writenbr(nbr * -1, fd);
	}
	else if (nbr > 0)
	{
		writenbr(nbr / 10, fd);
		ft_putchar_fd('0' + (nbr % 10), fd);
	}
}

//scrivi int <nbr> nel file descritto da <fd> come char
void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}

// scrive long int <nbr> nel file descritto da <fd> come char
void	ft_putlong_fd(long nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}
