/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comodetion_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:18:40 by sgalli            #+#    #+#             */
/*   Updated: 2023/02/01 12:09:09 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_tile	**alloc_backup(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		i++;
	}
	return (tilemap);
}

t_tiletype	define_tiletype(char definer);

t_tile	**ft_continue(t_tile **backup, char **map)
{
	int	x;
	int	y;

	backup = alloc_backup(map);
	if (backup == NULL)
		return (null_error("malloc error on alloc_tilemap()"));
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			backup[y][x].type = define_tiletype(map[y][x]);
			x++;
		}
		backup[y][x].type = '\0';
		y++;
	}
	backup[y] = NULL;
	return (backup);
}
