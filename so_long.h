/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:42:53 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/13 01:50:38 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"

# define WIN_HEIGHT 600
# define WIN_WIDTH 900
# define SQUARE 80
# define PLAYER_PATH "img/troll_white.xpm"
# define GRASS_PATH "img/grass.xpm"
# define WALL_PATH "img/wall.xpm"
# define SNACK_PATH "img/snack.xpm"
# define EXIT_PATH "img/exit.xpm"
# define STEP_BCGRND_PATH "img/step_bcgrnd.xpm"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map {
	int		width;
	int		height;
	int		size;
	char	**map_2D;
	int		collectibles;
}				t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	void	*img_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
}			t_player;

typedef struct s_game
{
	t_vars		*vars;
	t_map		*map;
	t_img		*grass;
	t_img		*wall;
	t_img		*snack;
	t_img		*exit;
	t_img		*step_bcgrnd;
	t_player	*player;
	int			steps;
	int			collect_max;
	int			collected;
	int			able_to_exit;
}				t_game;

void	check_WSAD_keys(int keycode, t_game *game);
int		key_hook(int keycode, t_game *game);
int		map_loader(t_game *game, char *map_file_name);
void	check_exit_game(int x, int y, t_game *game);
int		close_game(t_game *game);
void	message_exit(char *str, t_game *game);

/*	rendering	*/
void	render_next_frame(t_game *game);
void	render_walls_coll_exits(t_game *game);
void	render_grass(t_game *game);

/*	Initializers	*/
void	initializer(t_game *game);
void	initialize_player(t_game *game);
void	initialize_img(t_game *game, t_img *img, char *file_path);
void	initialize_images(t_game *game);

/* For map checker */
void	check_map(char *map_name, t_game *game, int argc);
void	check_start_pos(t_game *game);
void	check_collectibles(char *map_name, t_game *game);
void	check_exits(char *map_name, t_game *game);
void	check_walls(t_game *game);
void	check_coll_and_exits(t_game *game);

/*	Memory free	*/
void	map_2D_free(t_game *game);
void	mem_free(t_game *game);

/*	Function using for testing purposes	*/
void	print_map(t_game *game);

#endif