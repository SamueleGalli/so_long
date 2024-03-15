/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:24:52 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/26 10:09:27 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*typedef struct s_game
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
}	t_game;

typedef struct s_vector
{
	int     x;
	int     y;
}       t_vector;

*/
#include "../so_long.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anim(&game->effect, pos);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
}
