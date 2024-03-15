/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:07:48 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/19 11:05:01 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*typedef struct s_mapcheckerdata
{
        t_vector        size;
        t_vector        point;
        t_bool          b_player;
        t_bool          b_exit;
        t_bool          b_collect;
}                               t_mapcheckerdata;
*/

#include "map_bonus.h"

int	valid_char(char c);
int	valid_uniquechar(char c, char checker, t_bool *bool);
int	valid_border(char c, t_vector point, t_vector size);

//ritorna 1 se il file e valido
//altrimenti esegue test dove il file puo dare errore
int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("no args"));
	if (argc > 2)
		print_warning("only the first file would be used");
	if (ft_strend_cmp(file, ".ber") == 0)
		return (error("map should be a .ber file"));
	return (1);
}

//prendo la lunghezza della prima riga con map[0]
//prendo le righe delimitate da '/n'
//inizializzo i dati e li ritorno
static	t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

//controlla possibili errori di mappa
static int	checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (valid_char(map[y][x]) == 0)
		return (error("invalid map character"));
	if (valid_uniquechar(map[y][x], 'P', &data->b_player) == FALSE)
		return (error("must be only one player 'P'"));
	if (valid_uniquechar(map[y][x], 'E', &data->b_exit) == FALSE)
		return (error("must be only one exit 'E'"));
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (valid_border(map[y][x], data->point, data->size) == FALSE)
		return (error("map must be sourrended by walls '1'"));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

//metto i dati necessari
//valid diventa TRUE per controllare
//controllo se la prima righe e nulla con un ciclo
//controllo se e rettangolare in caso do errore
//controllo alcuni casi sulla stessa riga
//facendolo riga per riga
//se alla fine non trova o P o E o C da eerore
//alla fine ritorna TRUE o FALSE in base a valid
int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	t_bool				valid;

	data = init_checkerdata(map);
	valid = TRUE;
	while (map[data.point.y] != NULL)
	{
		if (ft_strlen(map[data.point.y]) != (size_t)data.size.x)
			valid = error("map must be rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x] != '\0')
		{
			if (checks(map, &data) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (data.b_player == 0 || data.b_exit == 0 || data.b_collect == 0)
		valid = error("there must be one 'P' and 'E', and at least one 'C'");
	return (valid);
}
