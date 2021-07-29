/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:55:58 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/13 01:49:44 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	check_exit_game()
**	Checking if the next field is an exit and
**		if player is allowed to exit.
**		If yes - writing message and exiting the game.
*/
void	check_exit_game(int x, int y, t_game *game)
{
	(game->steps)++;
	ft_printf("Step %d\n", game->steps);
	if ((game->map->map_2D[y][x] == 'E') && (game->able_to_exit))
	{
		ft_printf("Game Finished ! Score: %d\n", game->steps);
		close_game(game);
	}
}

/*	check_WSAD_keys()
**	Basic actions for WSAD keys.
**	If not exiting the game - player position modifications.
*/
void	check_WSAD_keys(int keycode, t_game *game)
{
	if (keycode == 'w')
	{
		check_exit_game(game->player->x, game->player->y - 1, game);
		if (game->map->map_2D[game->player->y - 1][game->player->x] != '1')
			game->player->y -= 1;
	}
	if (keycode == 's')
	{
		check_exit_game(game->player->x, game->player->y + 1, game);
		if (game->map->map_2D[game->player->y + 1][game->player->x] != '1')
			game->player->y += 1;
	}
	if (keycode == 'a')
	{
		check_exit_game(game->player->x - 1, game->player->y, game);
		if (game->map->map_2D[game->player->y][game->player->x - 1] != '1')
			game->player->x -= 1;
	}
	if (keycode == 'd')
	{
		check_exit_game(game->player->x + 1, game->player->y, game);
		if (game->map->map_2D[game->player->y][game->player->x + 1] != '1')
			game->player->x += 1;
	}
}

/*	overwrite_collectibles()
**	1. If field is an collectible - rewrite map to field ('0').
**	2. Increase collected value.
**	3. Check if player collected all items.
*/
static void	overwrite_collectibles(t_game *game)
{
	if (game->map->map_2D[game->player->y][game->player->x] == 'C')
	{
		game->map->map_2D[game->player->y][game->player->x] = '0';
		(game->collected)++;
	}
	if (game->collected == game->collect_max)
		game->able_to_exit = 1;
}

/*	key_hook()
**	Key press actions.
**	1. Increase game steps and print on the console.
**	2. If "ESC" pressed - exit game.
**	3. Render next frame.
*/
int	key_hook(int keycode, t_game *game)
{
	check_WSAD_keys(keycode, game);
	if (keycode == 65307)
		close_game(game);
	overwrite_collectibles(game);
	render_next_frame(game);
	return (1);
}
