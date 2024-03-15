/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digitcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:02:20 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/22 16:06:55 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//conte il numero di cifre di un intero
int	ft_digitcount(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

//conta il numero di cifre che un intero a in esadecimale
int	ft_hexlen(unsigned int num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

//conta il numero di cifre che un intero a in long esadecimale
int	ft_hexlen_long(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}
