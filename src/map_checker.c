/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:59:34 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/13 17:09:58 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	check_map_size()
**	checking size of the map provided as program argument
**	this size is later used as parameter for malloc (2D array map allocation)
*/
static void	check_map_size(char *map_name, t_game *game)
{
	int		fd;
	int		i;
	char	tmp[1];

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (read(fd, tmp, 1) == 1)
		i++;
	close(fd);
	game->map->size = i;
}

/*	check_map_width()
**	Checking width as the size of the first line
*/
static void	check_map_width(char *map_name, t_game *game)
{
	int		fd;
	int		i;
	char	tmp[1];

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (read(fd, tmp, 1) == 1)
	{
		if (tmp[0] == '\n')
			break ;
		i++;
	}
	close(fd);
	game->map->width = i;
}

/*	check_map_height()
**	Checking the height as the number of lines
*/
static void	check_map_height(char *map_name, t_game *game)
{
	int		fd;
	int		i;
	char	tmp[1];

	i = 1;
	fd = open(map_name, O_RDONLY);
	while (read(fd, tmp, 1) == 1)
	{
		if (tmp[0] == '\n')
			i++;
	}
	close(fd);
	game->map->height = i;
}

/*	check_map_rectangl()
**	Checking if the map is a correct rectangle.
*/
static void	check_map_rectangl(char *map_name, t_game *game)
{
	int		fd;
	int		i;
	char	tmp[1];

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (read(fd, tmp, 1) == 1)
	{
		i++;
		if (tmp[0] == '\n')
		{
			i--;
			if (i != game->map->width)
				message_exit("Error! Map is not a rectangle!!\n", game);
			i = 0;
		}
	}
	if (i != game->map->width)
		message_exit("Error! Map is not a rectangle!!\n", game);
	close(fd);
}

/*	check_map()
**	Main map checker.
**	1. Checking for correct number of arguments provided.
**	2. Callings all checker functions needed.
**	3. Loading the content of the map to the 2D-array.
*/
void	check_map(char *map_name, t_game *game, int argc)
{
	if (argc != 2)
		message_exit("Error! Wrong number of arguments!\n", game);
	check_map_size(map_name, game);
	check_map_height(map_name, game);
	check_map_width(map_name, game);
	check_map_rectangl(map_name, game);
	if (map_loader(game, map_name))
		message_exit("Map allocation fails!\nExiting...\n", game);
	check_coll_and_exits(game);
	check_start_pos(game);
	check_walls(game);
}
