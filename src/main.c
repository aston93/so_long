/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:13:37 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/12 23:37:19 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	Basic game engine
**	1. Initialization / memory allocations.
**	2. Map checking.
**	3. Creating new game window.
**	4. Graphic library loops - action if user press the button.
*/
int	main(int argc, char *argv[])
{
	t_game	game;

	initializer(&game);
	check_map(argv[1], &game, argc);
	game.vars->mlx = mlx_init();
	game.vars->win = mlx_new_window(game.vars->mlx,
			game.map->width * SQUARE, game.map->height * SQUARE, "so_long");
	initialize_images(&game);
	mlx_key_hook(game.vars->win, key_hook, &game);
	mlx_hook(game.vars->win, 33, (1L << 17), close_game, &game);
	mlx_loop(game.vars->mlx);
	return (0);
}
