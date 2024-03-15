/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:28:07 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/27 15:21:14 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct s_player
{
        t_tile  *tile;
        void    *current_img;
        int             framecount;
        int             idle_frames;
        void    *idle_img_0;
        void    *idle_img_1;
        int             action_frames;
        void    *action_img;
}       t_player;

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

typedef struct s_coll_img
{
        void    *current_img;
        int             anim_frames;
        void    *img_0;
        void    *img_1;
}       t_collect_img;

typedef struct s_effect
{
        void            *img;
        t_vector        pos;
        int                     frames;
        int                     counter;
}       t_effect;
*/
#include "../so_long.h"

void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter = effect->counter + 1;
}

//calcola tutte le animazioni e le mostra
//lo fa su ogni animazione
int	update(t_game *game)
{
	effect_animation(&game->effect);
	render(*game);
	return (1);
}
