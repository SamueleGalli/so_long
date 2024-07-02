/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:24:57 by sgalli            #+#    #+#             */
/*   Updated: 2024/07/02 14:00:14 by sgalli           ###   ########.fr       */
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

typedef enum e_tiletype
{
        EMPTY = '0',
        WALL = '1',
        COLLECTABLE = 'C',
        PLAYER = 'P',
        EXIT = 'E',
        ENEMY = 'M',
        FOLLOWER = 'F'
}       t_tiletype;  */

#include "map.h"

//alloca a tilemap il numero di righe
//cicla la mappa
//alloca a ogni elemento della matrice la lunghezza
//della prima riga
//se tilemap e nullo libero ogno elemento della matrice
//e ritorno null
//quando ho allocato tutta la dimensione ritorno tilemap
t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		i++;
	}
	return (tilemap);
}

//associo il tipo in base al carattere
t_tiletype	define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'P')
		return (PLAYER);
	if (definer == 'E')
		return (EXIT);
	if (definer == 'H' || definer == 'V')
		return (ENEMY);
	else if (definer == 'F')
		return (FOLLOWER);
	return (EMPTY);
}

//faccio diventare il tipo originale uguale a type
//e gli associo x e y
//definisco sinistra destra su e giu
void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].position.x = x * IMG_SIZE;
	tilemap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (y + 1 != 0)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	if (x + 1 != 0)
		tilemap[y][x].right = &tilemap[y][x + 1];
}

//aggiunge informazione alla struttura gioco se necessario
//aggiunge player collezionabili e nemici alla mappa
void	set_gamevars(t_tile *tile, t_game *game, char c)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COLLECTABLE)
		game->collects = game->collects + 1;
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
		add_enemy(game, c, tile);
}

//alloco con malloc la dimensione della mappa
//controllo errori
//ciclo la mappa partendo da[y] che indica la prima riga
//definisco ogni blocco
//posiziono i blocchi nella mappa
//inizzializzo le variabili al suo intenrno
//eseguo cio su ogni riga e colonna
//do alla finestra x e y dimensione
//ritorno la mappa
t_tile	**generate_tilemap(char **map, t_game *game)
{
	t_tile		**tilemap;
	int			x;
	int			y;

	tilemap = alloc_tilemap(map);
	if (tilemap == NULL)
		return (null_error("malloc error on alloc_tilemap()"));
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].type = define_tiletype(map[y][x]);
			setup_tile(tilemap, x, y);
			set_gamevars(&tilemap[y][x], game, map[y][x]);
			x++;
		}
		tilemap[y][x].type = '\0';
		y++;
	}
	tilemap[y] = NULL;
	game->wndw_size.x = x * IMG_SIZE;
	game->wndw_size.y = y * IMG_SIZE;
	return (tilemap);
}
