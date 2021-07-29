/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:52:34 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/12 23:32:23 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	render_grass()
**	Rendering the grass (background) on the whole window.
*/
void	render_grass(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(game->vars->mlx,
				game->vars->win, game->grass->img_ptr, j * SQUARE, i * SQUARE);
			j++;
		}
		i++;
	}
}

/*	render_walls_coll_exits()
**	Rendering walls, collectibles and exits on correct positions.
*/
void	render_walls_coll_exits(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->width)
	{
		j = 0;
		while (j < game->map->height)
		{
			if (game->map->map_2D[j][i] == '1')
				mlx_put_image_to_window(game->vars->mlx, game->vars->win,
					game->wall->img_ptr, i * SQUARE, j * SQUARE);
			else if (game->map->map_2D[j][i] == 'C')
				mlx_put_image_to_window(game->vars->mlx, game->vars->win,
					game->snack->img_ptr, i * SQUARE, j * SQUARE);
			else if (game->map->map_2D[j][i] == 'E')
				mlx_put_image_to_window(game->vars->mlx, game->vars->win,
					game->exit->img_ptr, i * SQUARE, j * SQUARE);
			j++;
		}
		i++;
	}
}

/*	render_next_frame()
**	Main rendering function.
**	1. Creating player enviroment (grass, walls etc.)
**	2. Rendering player on correct position.
**	3. Rendering frame with number of steps made.
*/
void	render_next_frame(t_game *game)
{
	char	*step_nbr;

	step_nbr = ft_itoa(game->steps);
	render_grass(game);
	render_walls_coll_exits(game);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win,
		game->player->img_ptr, game->player->x * SQUARE,
		game->player->y * SQUARE);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win,
		game->step_bcgrnd->img_ptr, 17, 17);
	mlx_string_put(game->vars->mlx,
		game->vars->win, 18, 30, 0x00000000, "Steps: ");
	mlx_string_put(game->vars->mlx,
		game->vars->win, 55, 30, 0x00000000, step_nbr);
	free(step_nbr);
}
