/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:33:49 by sgalli            #+#    #+#             */
/*   Updated: 2024/07/02 14:14:58 by sgalli           ###   ########.fr       */
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

typedef struct s_effect
{
        void            *img;
        t_vector        pos;
        int                     frames;
        int                     counter;
}       t_effect;

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
*/

#include "../so_long.h"

void	move_enemies(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	pick_collect(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

//piazze a avvia l'effetto particellare
void	effect_anim(t_effect *effect, t_vector pos)
{
	effect->counter = 0;
	effect->pos = pos;
}

//inizia la pose dell'animazione del giocatore
void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

//muove il giocatore al blocco faciendo cio che ha bisogno basandosi sul tipo
t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
	{
		move_to_enemy(game, tile);
		return (FALSE);
	}
	move_enemies(game);
	return (TRUE);
}

//gestione tasti.chiamato ogni volta che premi un tasto
int	input(int key, t_game *game)
{
	t_bool	moved;
	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved != 0)
	{
		game->moves = game->moves + 1;
		printf("key pressed = %d\n", game->moves);
	}
	return (1);
}
