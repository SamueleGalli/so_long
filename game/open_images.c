/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:33:16 by sgalli            #+#    #+#             */
/*   Updated: 2023/02/02 10:42:18 by sgalli           ###   ########.fr       */
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
}       t_game;
*/
#include "../so_long.h"

void	open_wallimgs_up(t_game *game);
void	open_wallimgs_down(t_game *game);

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/player_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/player_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.idle_img_0;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect/plant_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect/effect_w.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy/enemy_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(game->mlx,
			"sprites/follow/follow_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
}

static void	open_door_imgs(t_game *game)
{
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
}

//apre tutte le immagini neccessarie per il gioco
void	open_images(t_game *game)
{
	open_wallimgs_up(game);
	open_wallimgs_down(game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
	open_door_imgs(game);
}
