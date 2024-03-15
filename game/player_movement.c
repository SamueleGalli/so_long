/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:29:19 by sgalli            #+#    #+#             */
/*   Updated: 2023/02/02 11:21:40 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
typedef struct s_tile
{
	t_tiletype              type;
	t_tiletype              og_type;
	t_vector                position;
	struct s_tile   *up;
	struct s_tile   *down;
	struct s_tile   *left;
	struct s_tile   *right;
}       t_tile;
*/
#include "../so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->collects = game->collects - 1;
	effect_anim(&game->effect, tile->position);
	action_anim(&game->player);
}

void	move_to_exit(t_game *game, t_tile *tile)
{
	effect_anim(&game->effect, tile->position);
	remove_player(game);
	game->collects -= 1;
}

void	move_to_enemy(t_game *game, t_tile *tile)
{
	remove_player(game);
	effect_anim(&game->effect, tile->position);
	kill_player(game, tile->position);
}
