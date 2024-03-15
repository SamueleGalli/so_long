/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:59:38 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/19 11:03:54 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include "../gnl_bonus/get_next_line_bonus.h"

//apre il file e legge lettera per lettera fino alla fine
//di seguito aggiorna linecount e lo ripete finche il file letto e 0
//chiude il file e ritorna le righe lette
static int	file_linecount(char *file)
{
	int			linecount;
	int			fd;
	int			readcount;
	char		c;

	fd = open(file, O_RDONLY);
	if (fd == 0)
		return (-1);
	linecount = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount = linecount + 1;
	}
	close(fd);
	return (linecount);
}

//conta il numero di linee con file_linecount
//controlla possibili errori
//ritorna la mappa formata dalle righe map[y]
static char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (null_error("open or reading error,the file may not exist"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("malloc error on alloc_map()"));
	return (map);
}

//alloca a map n colonne definite in alloc_columns
//controlla errori
//apre il file e legge ogni riga fino alla fine con get_next_line
//associa il carattere nullo e chiude il file
//ritorna la mappa
char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i]) != '\0')
	{
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
