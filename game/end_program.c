/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:02:47 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/26 10:12:42 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_enemy
{
        t_enemytype                     type;
        int                                     dir;
        t_tile                          *og_tile;
        t_tile                          *tile;
        struct s_enemy          *next;
}       t_enemy;

*/
#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;
	t_tile	**b;

	b = game->backup;
	tilemap = game->tilemap;
	while (*tilemap != NULL)
	{
		free(*b);
		free(*tilemap);
		tilemap++;
		b++;
	}
}

void	free_enemies(t_game *game)
{
	t_enemy	*tmp;

	if (game->enemy_list == NULL)
	{
		return ;
	}
	while (game->enemy_list != NULL)
	{
		if (game->enemy_list->next != NULL)
		{
			tmp = game->enemy_list;
			game->enemy_list = game->enemy_list->next;
			free(tmp);
		}
		else
		{
			free(game->enemy_list);
			break ;
		}
	}
}

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_imgs.block);
	mlx_destroy_image(game->mlx, game->wall_imgs.up_left);
	mlx_destroy_image(game->mlx, game->wall_imgs.up);
	mlx_destroy_image(game->mlx, game->wall_imgs.up_right);
	mlx_destroy_image(game->mlx, game->wall_imgs.right);
	mlx_destroy_image(game->mlx, game->wall_imgs.down_right);
	mlx_destroy_image(game->mlx, game->wall_imgs.down);
	mlx_destroy_image(game->mlx, game->wall_imgs.down_left);
	mlx_destroy_image(game->mlx, game->wall_imgs.left);
	mlx_destroy_image(game->mlx, game->player.idle_img_0);
	mlx_destroy_image(game->mlx, game->player.action_img);
	mlx_destroy_image(game->mlx, game->collects_imgs.img_0);
	mlx_destroy_image(game->mlx, game->effect.img);
	mlx_destroy_image(game->mlx, game->enemy_imgs.basic_01);
	mlx_destroy_image(game->mlx, game->enemy_imgs.follow_01);
	mlx_destroy_image(game->mlx, game->door_open_img);
	mlx_destroy_image(game->mlx, game->door_close_img);
}

// libera la memoria e esce
int	end_program(t_game *game)
{
	free_tilemap(game);
	free(game->tilemap);
	free(game->backup);
	free_enemies(game);
	free_image(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
