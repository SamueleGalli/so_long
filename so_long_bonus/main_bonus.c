/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:30:17 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/30 14:27:16 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basics_bonus.h"
#include "map_bonus/map_bonus.h"
#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (start(&game, argc, argv) == FALSE)
		return (0);
	mlx_hook(game.window, 2, 1L << 0, input, (void *)&game);
	mlx_hook(game.window, 17, 0, end_program, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
