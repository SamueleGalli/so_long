/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:15:49 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/12 12:20:20 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

/*typedef enum e_bool
{
        TRUE = 1;
        FALSE = 0;
}       t_bool;
*/
/*typedef struct s_tile
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
/*typedef struct s_vector
{
        int     x;  
        int     y;  
}       t_vector;
*/
/*typedef struct s_game
{
        void                    *mlx;
        void                    *window;
        t_vectore               wndw_size;
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
t_bool	draw_corner(t_tile tile, t_game game, t_vector pos)
{
	if (tile.position.x == 0 \
		&& tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.up_left, pos.x, pos.y);
	else if (tile.position.x == 0 \
		&& tile.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.down_left, pos.x, pos.y);
	else if (tile.position.x == game.wndw_size.x - IMG_SIZE \
		&& tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.up_right, pos.x, pos.y);
	else if (tile.position.x == game.wndw_size.x - IMG_SIZE \
		&& tile.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.down_right, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	draw_sides(t_tile tile, t_game game, t_vector pos)
{
	if (tile.position.x == 0)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.left, pos.x, pos.y);
	else if (tile.position.x == game.wndw_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.right, pos.x, pos.y);
	else if (tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.up, pos.x, pos.y);
	else if (tile.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window, \
			game.wall_imgs.down, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	if (draw_corner(tile, game, pos) == TRUE)
		return ;
	else if (draw_sides(tile, game, pos) == TRUE)
		return ;
	mlx_put_image_to_window(game.mlx, game.window, \
		game.wall_imgs.block, pos.x, pos.y);
}
