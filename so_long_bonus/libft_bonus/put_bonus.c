/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:08:27 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/03 10:36:00 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_bonus.h"

//scrive char <c> nel file descritto da <fd>
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

//scrive <str> nel file descritto da <fd>
void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}

//scrive <str> nel file descritto da <fd> seguito da \n
void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
