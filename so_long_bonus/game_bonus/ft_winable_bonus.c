/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:26:51 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/26 10:26:53 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// int	border(int x, int y, t_tile **g, int con)
// {
// 	int x1;
// 	int x2;
// }

void	mover(int x, int y, t_tile **g)
{
	if (g[y + 1][x].type == EMPTY || g[y + 1][x].type == EXIT \
	|| g[y + 1][x].type == COLLECTABLE || g[y + 1][x].type == ENEMY \
	|| g[y + 1][x].type == FOLLOWER)
	{
		g[y + 1][x].type = WALL;
		mover(x, y + 1, g);
	}
	if (g[y - 1][x].type == EMPTY || g[y - 1][x].type == EXIT \
	|| g[y - 1][x].type == COLLECTABLE || g[y - 1][x].type == ENEMY \
	|| g[y - 1][x].type == FOLLOWER)
	{
		g[y - 1][x].type = WALL;
		mover(x, y - 1, g);
	}
}

void	radar(int x, int y, t_tile **g)
{
	if (g[y][x + 1].type == EMPTY || g[y][x + 1].type == EXIT \
	|| g[y][x + 1].type == COLLECTABLE || g[y][x + 1].type == ENEMY \
	|| g[y][x + 1].type == FOLLOWER)
	{
		g[y][x + 1].type = WALL;
		mover(x + 1, y, g);
	}
	if (g[y][x - 1].type == EMPTY || g[y][x - 1].type == EXIT \
	|| g[y][x - 1].type == COLLECTABLE || g[y][x - 1].type == ENEMY \
	|| g[y][x - 1].type == FOLLOWER)
	{		
		g[y][x - 1].type = WALL;
		mover(x - 1, y, g);
	}
}

t_bool	ft_while(int x, int y, t_tile **g)
{
	y = 0;
	while (g[y] != NULL)
	{
		x = 1;
		while (g[y][x].type != '\0')
		{
			if (g[y][x].type == 'E' || g[y][x].type == 'C')
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	ft_condition(int x, int y, t_tile **g)
{
	while (g[y] != NULL)
	{
		x = 1;
		while (g[y][x].type != '\0')
		{
			if (g[y][x].type == 'P')
			{
				g[y][x].type = WALL;
				mover(x, y, g);
				break ;
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

t_bool	ft_winnable(t_tile **backup)
{
	return (ft_condition(1, 1, backup));
}
