/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:59:28 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/13 01:58:32 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	map_loader()
**	1. Allocating memory for 2D-array map.
**	2. Rewiting map from file to array.
**	3. Exits if allocation fails.
*/
int	map_loader(t_game *game, char *map_file_name)
{
	int	fd;
	int	i;
	int	tmp[1];

	i = 0;
	fd = open(map_file_name, O_RDONLY);
	game->map->map_2D = (char **)malloc(sizeof(char **) * game->map->height);
	if (game->map->map_2D == NULL)
		return (EXIT_FAILURE);
	while (i < game->map->height)
	{
		game->map->map_2D[i] = (char *)malloc(
				sizeof(char *) * game->map->width + 1);
		if (game->map->map_2D[i] == NULL)
			return (EXIT_FAILURE);
		read(fd, game->map->map_2D[i], game->map->width);
		game->map->map_2D[i][game->map->width] = '\0';
		i++;
		read(fd, tmp, 1);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

/*	print_map()
**	Printing the 2D map in console (testing purposes).
*/
void	print_map(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("Map height: %d\n", game->map->height);
	ft_printf("Map width: %d\n", game->map->width);
	ft_printf("Printing the map:\n");
	while (i < game->map->height)
	{
		ft_printf("Row %d: %s\n", i + 1, game->map->map_2D[i]);
		i++;
	}
}

/*	close_game()
**	Closing window and exiting the game.
*/
int	close_game(t_game *game)
{
	mem_free(game);
	exit(0);
	return (0);
}

/*	map_2D_free()
**	Releasing memory of 2D map.
*/
void	map_2D_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->map_2D[i])
			free(game->map->map_2D[i]);
		i++;
	}
	if (game->map->map_2D)
		free(game->map->map_2D);
}

/*	mem_free()
**	General memory releasing.
*/
void	mem_free(t_game *game)
{
	if (game->player->img_ptr)
		mlx_destroy_image(game->vars->mlx, game->player->img_ptr);
	free(game->player);
	if (game->grass->img_ptr)
		mlx_destroy_image(game->vars->mlx, game->grass->img_ptr);
	free(game->grass);
	if (game->wall->img_ptr)
		mlx_destroy_image(game->vars->mlx, game->wall->img_ptr);
	free(game->wall);
	if (game->snack->img_ptr)
		mlx_destroy_image(game->vars->mlx, game->snack->img_ptr);
	free(game->snack);
	if (game->exit->img_ptr)
		mlx_destroy_image(game->vars->mlx, game->exit->img_ptr);
	free(game->exit);
	if (game->step_bcgrnd->img_ptr)
		mlx_destroy_image(game->vars->mlx, game->step_bcgrnd->img_ptr);
	free(game->step_bcgrnd);
	if (game->vars->win)
		mlx_destroy_window(game->vars->mlx, game->vars->win);
	if (game->vars->mlx)
		mlx_destroy_display(game->vars->mlx);
	map_2D_free(game);
	free(game->map);
	free(game->vars);
}
