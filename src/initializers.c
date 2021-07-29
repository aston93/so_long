/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:46:17 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/13 16:54:03 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	initialize_player()
**	1. Re-writing starting pos. to rendering frame pos.
**	2. Allocating memory and downloading picture from the drive.
*/
void	initialize_player(t_game *game)
{
	game->player->x = game->player->start_x;
	game->player->y = game->player->start_y;
	game->player->width = SQUARE;
	game->player->height = SQUARE;
	game->player->img_ptr = mlx_xpm_file_to_image(game->vars->mlx,
			PLAYER_PATH, &game->player->width, &game->player->height);
}

/*	initialize_img()
**	Multi-use function. For any image:
**	Allocating memory and downloading picture from the drive.
*/
void	initialize_img(t_game *game, t_img *img, char *file_path)
{
	img->width = SQUARE;
	img->height = SQUARE;
	img->img_ptr = mlx_xpm_file_to_image
		(game->vars->mlx, file_path, &img->width, &img->height);
}

/*	initializer()
**	1. Memory initialization for data structures.
**	2. Checking if initialization fails
**	3. Setting initial values
*/
void	initializer(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	game->vars = (t_vars *)malloc(sizeof(t_vars));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->wall = (t_img *)malloc(sizeof(t_img));
	game->snack = (t_img *)malloc(sizeof(t_img));
	game->grass = (t_img *)malloc(sizeof(t_img));
	game->exit = (t_img *)malloc(sizeof(t_img));
	game->step_bcgrnd = (t_img *)malloc(sizeof(t_img));
	if (!(game->map) || !(game->vars) || !(game->step_bcgrnd)
		|| !(game->player) || !(game->wall) || !(game->snack)
		|| !(game->grass) || !(game->exit))
		message_exit("Initializer failed...Exiting...\n", game);
	game->steps = 0;
	game->collected = 0;
	game->collect_max = 0;
	game->able_to_exit = 0;
}

/*	initialize_images()
**	1. Wrapped-up images initializations.
**	2. Rendering initial frame.
*/
void	initialize_images(t_game *game)
{
	initialize_player(game);
	initialize_img(game, game->grass, GRASS_PATH);
	initialize_img(game, game->wall, WALL_PATH);
	initialize_img(game, game->snack, SNACK_PATH);
	initialize_img(game, game->exit, EXIT_PATH);
	initialize_img(game, game->step_bcgrnd, STEP_BCGRND_PATH);
	render_next_frame(game);
}
