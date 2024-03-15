/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:28:07 by sgalli            #+#    #+#             */
/*   Updated: 2023/02/01 15:16:42 by sgalli           ###   ########.fr       */
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
#include "../so_long_bonus.h"

static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
	{
		player->current_img = player->idle_img_1;
	}
	else if (player->framecount == player->idle_frames)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount = player->framecount + 1;
}

static void	collec_animation(t_collect_img *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
	{
		img->current_img = img->img_0;
	}
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame = frame + 1;
}

static void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter = effect->counter + 1;
}

static void	enemy_animation(t_enemy_img *img)
{
	static int	basic_count;
	static int	follower_count;

	if (basic_count == img->basic_anim)
		img->basic_current = img->basic_01;
	else if (basic_count > img->basic_anim * 2)
	{
		img->basic_current = img->basic_02;
		basic_count = 0;
	}
	basic_count++;
	if (follower_count == img->follow_anim)
		img->follow_current = img->follow_01;
	else if (follower_count > img->follow_anim * 2)
	{
		img->follow_current = img->follow_02;
		follower_count = 0;
	}
	follower_count = follower_count + 1;
}

//calcola tutte le animazioni e le mostra
//lo fa su ogni animazione
int	update(t_game *game)
{
	static int	i = 0;

	if (i > 800)
	{
		collec_animation(&game->collects_imgs);
		effect_animation(&game->effect);
		enemy_animation(&game->enemy_imgs);
		player_animation(&game->player);
		i = 0;
	}
	i++;
	render(*game);
	return (1);
}
