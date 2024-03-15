/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:00:17 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/09 10:54:18 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../libft_bonus/libft_bonus.h"

//controlla se line da errori
//misura la lunghezza della linea fino a '\n'
int	ft_linelen(char *line)
{
	int	i;

	if (line == 0)
		return (-1);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//crea un malloc lungo linelen
//metto in line readbuff
//ritorno line
char	*ft_getline(int len, char *read)
{
	char	*line;
	int		i;

	line = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

//controlla errori
//togli bit allocati con malloc
//ciclo e alloco in output i bit successivi a quelli letti
//libero read e retituisco l'output
char	*ft_clearline(int len, char *read)
{
	char	*output;
	int		i;

	if (read == NULL || (ft_strlen(read) - len + 1) == 0)
		return (NULL);
	output = malloc(ft_strlen(read) - len + 1);
	i = 0;
	while (read[len + i] != '\0')
	{
		output[i] = read[len + i];
		i++;
	}
	output[i] = '\0';
	free(read);
	return (output);
}

//leggi

//inizzializza newread con BUFFER_SIZE byte
///mette dentro count BUFFER_SIZE byte di newread
//somma alla vecchia lettura count + il carattere nullo
//mette in output la seguente oldread per la sua lunghezza totale
//mette in output tutte le righe
//libera oldread
//mette il oldread tutta la lettura
//ritorna la lunghezza count
int	ft_newread(int fd, char **oldread)
{
	int		count;
	char	newread[BUFFER_SIZE + 1];
	char	*output;
	int		i;
	int		new_i;

	count = read(fd, newread, BUFFER_SIZE);
	newread[count] = '\0';
	output = malloc(ft_strlen(*oldread) + count + 1);
	if (output == NULL)
		return (-1);
	i = 0;
	while (oldread[0][i] != '\0')
	{
		output[i] = oldread[0][i];
		i++;
	}
	new_i = 0;
	while (newread[new_i] != '\0')
		output[i++] = newread[new_i++];
	output[i] = '\0';
	free(*oldread);
	*oldread = output;
	return (count);
}
