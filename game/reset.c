/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:14:24 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/24 12:21:54 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*typedef struct s_enemy
{
		t_enemytype                     type;
		int                                     dir;
		t_tile                          *og_tile;
		t_tile                          *tile;
		struct s_enemy          *next;
}	t_enemy;

typedef struct s_game
{
		void                    *mlx;
		void                    *window;
		t_vector                wndw_size;
		t_tile                  **tilemap;
		t_player                player;
		int                             og_collects;
		int                             collects;
		int                             moves;
		t_enemy                 *enemy_list;
		t_vector                img_size;
		t_wall_img              wall_imgs;
		t_collect_img   collects_imgs;
		t_enemy_img             enemy_imgs;
		void                    *door_open_img;
		void                    *door_close_img;
		t_effect                effect;
		void                    *red_panel;
		void                    *white_panel;
}       t_game;

*/

#include "../so_long.h"

static void	reset_enemies(t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	while (TRUE)
	{
		enemy->tile = enemy->og_tile;
		enemy->dir = 0;
		if (enemy->next == NULL)
			break ;
		enemy = enemy->next;
	}
}

// fa ritornare il gioco al suo stato originale
// ciclo la matrice
// ciclo finche non arrivo all'ultimo tile
// ripristino il loro tipo
int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->tilemap[y] != NULL)
	{
		x = 0;
		while (game->tilemap[y][x].type != 0)
		{
			game->tilemap[y][x].type = game->tilemap[y][x].og_type;
			if (game->tilemap[y][x].type == PLAYER)
			{
				game->player.tile = &game->tilemap[y][x];
			}
			x++;
		}
		y++;
	}
	reset_enemies(game->enemy_list);
	game->moves = 0;
	game->collects = game->og_collects;
	return (0);
}
