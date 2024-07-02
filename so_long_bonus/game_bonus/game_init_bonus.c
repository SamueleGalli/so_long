/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:00:27 by sgalli            #+#    #+#             */
/*   Updated: 2024/07/02 14:15:02 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "../map_bonus/map_bonus.h"

void	open_images(t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);
//controlla possibili errori
//creaa una mappa con malloc basandosi sul primo file che argv riceve
//ritorna NULL se ci sono errori

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (valid_file(argc, argv[1]) == 0)
		return (NULL);
	map = read_map(argv[1]);
	if (map == NULL)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	if (tilemap == NULL)
		end_program(game);
	game->backup = ft_continue(game->backup, map);
	if (game->backup == NULL)
		end_program(game);
	ft_free_chartable(map);
	if (tilemap == NULL)
		return (NULL);
	return (tilemap);
}

#include <stdio.h>
//inizia l'mlx, apre una finestra, e apre un immagine
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"so_long");
	open_images(game);
	if (ft_winnable(game->backup) == FALSE)
	{
		error("no space to win the game");
		end_program(game);
	}
	game->death = 0;
	game->win = 0;
}

//mette i fotogrammi di ogni animazione
static void	anim_setup(t_game *game)
{
	game->player.framecount = 0;
	game->effect.counter = 0;
	game->player.idle_frames = 1;
	game->player.action_frames = 1;
	game->collects_imgs.anim_frames = 1;
	game->effect.frames = 1;
	game->enemy_imgs.basic_anim = 1;
	game->enemy_imgs.follow_anim = 1;
}

//inizializza la struttura gioco
//controlla se la mappa e valida e se lo e inizzializza tilemap
//controlla errori di mappa
//sttiva le animazioni
//avvia il gioco
t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->enemy_list = NULL;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	anim_setup(game);
	game_init(game);
	return (TRUE);
}
