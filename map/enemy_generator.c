/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:54:57 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/19 11:05:46 by sgalli           ###   ########.fr       */
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

typedef enum e_enemytype
{
        HORIZONTAL_ENEMY = 'H',
        VERTICAL_ENEM = 'V',
        FOLLOW_ENEM = 'F',
}       t_enemytype;

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

#include "map.h"

//crea con malloc un nemico con <tipo> e <blocco>
t_enemy	*new_enemy(t_enemytype type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		return (null_error("malloc error on new_enemy()"));
	enemy->type = type;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->og_tile = enemy->tile;
	enemy->next = NULL;
	return (enemy);
}

//ritorna un puntatore all'ultimo elemento della lista
t_enemy	*last_enemy(t_enemy *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

//aggiunge con malloc un nemico alla fine della lista
void	add_enemy(t_game *game, t_enemytype type, t_tile *tile)
{
	t_enemy	*new;

	new = new_enemy(type, tile);
	if (new == NULL)
		return ;
	if (game->enemy_list == NULL)
	{
		game->enemy_list = new;
	}
	else
		last_enemy(game->enemy_list)->next = new;
}
