/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:08 by sgalli            #+#    #+#             */
/*   Updated: 2024/07/02 13:51:06 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
typedef struct s_vector
{
        int     x;
        int     y;
}       t_vector;
*/
#include "../so_long.h"

void	draw_wall(t_tile tile, t_game game, t_vector pos);

//disegna l'immagine sul corrispettivo blocco
static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		if (game.collects != 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_close_img, pos.x, pos.y);
		if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_open_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs.img_0, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.idle_img_0, pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.enemy_imgs.basic_01, pos.x, pos.y);
	else if (tile.type == FOLLOWER)
		mlx_put_image_to_window(game.mlx, game.window,
			game.enemy_imgs.follow_01, pos.x, pos.y);
}

//se il contatore di effeti e minore dei frame da animare, disegnalo
static void	draw_effect(t_game game)
{
	if (game.effect.counter < game.effect.frames)
		mlx_put_image_to_window(game.mlx, game.window,
			game.effect.img,
			game.effect.pos.x, game.effect.pos.y);
}

//mette i blocchi della mappa nella finestra
void	render(t_game game)
{
	t_tile			tile;
	int				x;
	int				y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			draw_effect(game);
			x++;
		}
		y++;
	}
	if (game.death == 1 || game.win == 1)
		end_program(&game);
}
