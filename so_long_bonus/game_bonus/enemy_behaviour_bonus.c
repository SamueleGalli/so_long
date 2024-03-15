/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:31:51 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/26 14:03:27 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
typedef struct s_enemy
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
#include "../so_long_bonus.h"

void	follow_player(t_enemy *enemy, t_game *game);

//cambia il blocco del nemico
void	move_enemy_to(t_enemy *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	if (enemy->type == FOLLOW_ENEM)
		tile->type = FOLLOWER;
	else
		tile->type = ENEMY;
	enemy->tile = tile;
}

//se "nemico" direzione e 0, mettilo a 1
//se e 1, mettilo a 0
t_bool	change_dir(t_enemy *enemy)
{
	if (enemy->dir == 0)
		enemy->dir = 1;
	else
		enemy->dir = 0;
	return (FALSE);
}

//muove il nemico a sinistra o a destra in base alla direzione
t_bool	move_hor(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->left);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy->dir == 1)
	{
		if (enemy->tile->right->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->right);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

//muove il nemico sopra o sotto basato sulla direzione)
t_bool	move_ver(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->up);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy->dir == 1)
	{
		if (enemy->tile->down->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->down);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

//muove il nemico in base al tipo
void	move_enemies(t_game *game)
{
	t_enemy	*current;

	if (game->enemy_list == NULL)
		return ;
	current = game->enemy_list;
	while (TRUE)
	{
		if (current->type == HORIZONTAL_ENEMY)
			move_hor(current, game);
		else if (current->type == VERTICAL_ENEM)
			move_ver(current, game);
		else if (current->type == FOLLOW_ENEM)
			follow_player(current, game);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}
