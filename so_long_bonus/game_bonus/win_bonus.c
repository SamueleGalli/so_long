/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:22:19 by sgalli            #+#    #+#             */
/*   Updated: 2023/02/02 10:32:02 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	death(t_game game, int i)
{
	mlx_clear_window(game.mlx, game.window);
	while (i < 900000)
	{
		mlx_string_put(game.mlx, game.window, game.wndw_size.x / 2 - 20, \
		game.wndw_size.y / 2, \
		16711680, "GAME OVER");
		i++;
	}
	end_program(&game);
}

void	death_win(t_game game)
{
	int	i;

	i = 0;
	if (game.win == 1)
	{
		mlx_clear_window(game.mlx, game.window);
		while (i < 900000)
		{
			mlx_string_put(game.mlx, game.window, \
			game.wndw_size.x / 2 - 20, game.wndw_size.y / 2, \
			65280, "VICTORY!");
			i++;
		}
		end_program(&game);
	}
	else if (game.death == 1)
	{
		death(game, i);
	}
}
