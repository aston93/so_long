/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:59:34 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/13 16:54:49 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	check_start_pos()
**	1. Check if the map contains only one start position
**	2. Inicialization of starting position
*/
void	check_start_pos(t_game *game)
{
	int		i;
	int		j;
	int		start_pos_nbr;

	i = 0;
	start_pos_nbr = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map_2D[i][j] == 'P')
			{
				start_pos_nbr++;
				game->player->start_x = j;
				game->player->start_y = i;
			}
			j++;
		}
		i++;
	}
	if (start_pos_nbr != 1)
		message_exit("Error! Check starting position !\n", game);
}

/*
**	check_coll_and_exits()
**	Check if the map contains correct number of collectibles and exits
*/
void	check_coll_and_exits(t_game *game)
{
	int	exits;
	int	i;
	int	j;

	exits = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map_2D[i][j] == 'C')
				(game->collect_max)++;
			else if (game->map->map_2D[i][j] == 'E')
				exits++;
			j++;
		}
		i++;
	}
	if ((game->collect_max < 1) || (exits < 1))
		message_exit("Error! Check collectibles and exits!\n", game);
}

/*
**	message_exit()
**	Simply prints the message and exits the program
*/
void	message_exit(char *str, t_game *game)
{
	ft_printf(str);
	mem_free(game);
	exit(EXIT_FAILURE);
}

/*
**	check_walls()
**	Check if the map is surrounded by the walls
*/
void	check_walls(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map->height)
	{
		if ((i == 0) || (i == game->map->height - 1))
		{
			j = 0;
			while (j < game->map->width)
			{
				if (game->map->map_2D[i][j] != '1')
					message_exit("Error - check walls !\n", game);
				j++;
			}
		}
		else
		{
			j = 0;
			if ((game->map->map_2D[i][0] != '1') ||
				(game->map->map_2D[i][game->map->width - 1] != '1'))
				message_exit("Error - check walls !\n", game);
		}
		i++;
	}
}
