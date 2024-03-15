/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:39:08 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/19 11:13:31 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../libft_bonus/libft_bonus.h"

/*ritorna -1 se i parametri non sono validi
se valid ritorna 1 e mette <readbuff> in
una stringa vuota se e nullo*/
int	validparams(int fd, char **line, char **readbuff)
{
	if (*readbuff == NULL)
	{
		*readbuff = malloc(sizeof(char));
		if (*readbuff == NULL)
			return (-1);
		**readbuff = '\0';
	}
	if (fd < 0 || line == 0
		|| BUFFER_SIZE <= 0 || fd > 4096)
	{
		free(*readbuff);
		*readbuff = NULL;
		return (-1);
	}
	return (1);
}

// int	end_of_read(int rdcount, char **readbuff, char **line)
// {
// 	int	len;ft_getline(linelen, readb

//inizzializzo readbuff ""
//misura la linea inizia con 0
//se la linea e < 0 entra in un loop
//contare tutta la mappa in in.ber e 18
//controllo errori
//alloca i primi bit fino a /n in min.ber 5
//esce dal ciclo 
int	get_next_line(int fd, char **line)
{
	static char	*readbuff;
	int			linelen;
	int			readcount;

	if (validparams(fd, line, &readbuff) < 0)
		return (-1);
	linelen = ft_linelen(readbuff);
	while (linelen < 0)
	{
		readcount = ft_newread(fd, &readbuff);
		if (readbuff == NULL || readcount < 0)
			return (-1);
		else if (readcount == 0)
		{
			free (readbuff);
			return (0);
		}
		linelen = ft_linelen(readbuff);
	}
	*line = ft_getline(linelen, readbuff);
	readbuff = ft_clearline(linelen + 1, readbuff);
	return (1);
}
