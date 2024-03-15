/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follower_behaviour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:22:02 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/03 16:41:54 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*typedef struct s_enemy
{
        t_enemytype                     type;
        int                                     dir;
        t_tile                          *og_tile;
        t_tile                          *tile;
        struct s_enemy          *next;
}       t_enemy;
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

t_bool	move_hor(t_enemy *enemy, t_game *game);
t_bool	move_ver(t_enemy *enemy, t_game *game);

/* ritorna 1 se il valore e negativo
0 se positivo
e -1 se e esattamente 0*/
int	define_dir(int value)
{
	if (value < 0)
		return (1);
	else if (value > 0)
		return (0);
	return (-1);
}

//muove il nemico su un blocco vicino al giocatore
void	follow_player(t_enemy *enemy, t_game *game)
{
	int	dis_x;
	int	dis_y;

	if (game->player.tile == NULL)
		return ;
	dis_x = enemy->tile->position.x - game->player.tile->position.x;
	dis_y = enemy->tile->position.y - game->player.tile->position.y;
	if (dis_x > dis_y)
	{
		enemy->dir = define_dir(dis_x);
		if (move_hor(enemy, game) == 0 || enemy->dir == -1)
		{
			enemy->dir = define_dir(dis_y);
			move_ver(enemy, game);
		}
	}
	else
	{
		enemy->dir = define_dir(dis_y);
		if (move_ver(enemy, game) == 0 || enemy->dir == -1)
		{
			enemy->dir = define_dir(dis_x);
			move_hor(enemy, game);
		}
	}
}
