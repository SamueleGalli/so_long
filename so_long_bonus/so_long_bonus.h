/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:21:11 by sgalli            #+#    #+#             */
/*   Updated: 2024/07/02 14:15:00 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "basics_bonus.h"
# include "minilibx-linux/mlx.h"

//dimensione di ogni sprite
# define IMG_SIZE 16

// tipo di blocco(tiles)

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F',
}	t_tiletype;

/* struttura di ogni blocco
(type) il tipo
(og_type) resetta gioco
(position) coordinate pixel
(s_tile) movimento
*/
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

// immagini

/* tutti le possibili immagini dei muri
(block) blocco muro
gli altri per la posizione 
*/
typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

/* information animazione collezzionabili
(img_0) primo frame per animare
(img_1) secondo frame per animare*/
typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

/*informaioni per gli effetti particellari
(frames) frame
(counter) contatore frame*/
typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

//un immagine per coprire l'intera finestra
//(endian) cambia colore
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

//colore
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

//nemici
typedef enum e_enemytype
{
	HORIZONTAL_ENEMY = 'H',
	VERTICAL_ENEM = 'V',
	FOLLOW_ENEM = 'F'
}	t_enemytype;

/*informazioni animazione nemici*/
typedef struct s_enemy_imgs
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;
	int		follow_anim;
	void	*follow_current;
	void	*follow_01;
	void	*follow_02;
}	t_enemy_img;

/*struttera per creare una lista di nemici
(type) tipo nemico
(dir) direzione
(og_tile) blocco
(next) nemico successino*/
typedef struct s_enemy
{
	t_enemytype			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

/* tutti i tasti validi
TASTI :
up = su
down = giu
left = sinistra
right = destra
reset = chiudere 
esc = chiudi 
*/
enum e_keycode
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	RESET = 114,
	ESC = 65307
};

/*informazioni riguardo il giocatore
(idle_img_0) prima immagine
(idle_img_1) seconda immagine
(action frame) fotogrammo di azione
(action_img) l'azione
*/
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

/* tutte le informazioni per l'avvio del gioco
(mlx) puntatore minilib
(window) finestra di gioco
(wndw_size) grandezza finestra
(tilemap) blocchi della mappa
(player) giocatore
(og_collects) oggetti collezzionabili
(collects) raccogli
(moves) movimento
(enemy_list) lista_nemici
(img_size) grandezza immagine
(wall_img) immagine muro
(collects_imgs) immagine collezionabili
(enemy_imgs) immagine nemici
(door_open_image) animazione apertura porta
(door_close_img) immagine chiusura porta
(effect) effetti
(red_panel) effetto schermo rosso
(white_panel) effetto schermo bianco
*/
typedef struct s_game
{
	t_tile				**tilemap;
	t_tile				**backup;
	void				*mlx;
	t_enemy				*enemy_list;
	void				*window;
	void				*door_open_img;
	void				*door_close_img;
	t_vector			wndw_size;
	t_player			player;
	t_vector			img_size;
	t_wall_img			wall_imgs;
	t_collect_img		collects_imgs;
	t_enemy_img			enemy_imgs;
	t_effect			effect;
	int					og_collects;
	int					collects;
	int					moves;
	int					win;
	int					death;
}	t_game;

//FUNCTIONI
//(start) avvia gioco

t_bool	start(t_game *game, int argc, char **argv);
t_bool	ft_winnable(t_tile **backup);

//(t_color) colori
//(new_panel) apri finestra
t_color	new_color(int r, int g, int b, int a);
void	*new_panel(t_game *game, t_color color);

//(input) premi tasti
//(update) riavvio gioco
//(render) raggio
int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);

//(effect_anim) effetti di animazione
//(action_effect) effetto di azionamento
void	effect_anim(t_effect *effect, t_vector pos);
void	action_anim(t_player *player);

//(remove_player)rimuove giocatore a morte
//(kill_player) morte giocatore
//(reset) resettare gioco
//(end_program) fine programma
void	death_win(t_game game);
void	remove_player(t_game *game);
void	kill_player(t_game *game, t_vector t_tile);
int		reset(t_game *game);
int		end_program(t_game *game);

t_tile	**ft_continue(t_tile **backup, char **map);

#endif
