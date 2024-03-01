/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2024/03/01 13:45:10 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectibles_collected;
	int		exitcount;
	int		exit_reached;
	int		player_x;
	int		player_y;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}			t_complete;

int			exit_point(t_complete *game);
int			map_reading(t_complete *game, char **argv);
int			controls_working(int command, t_complete *game);
void		adding_in_graphics(t_complete *game);
void		place_images_in_game(t_complete *game);
void		check_errors(t_complete *game);
void		valid_path(t_complete *game);
int			is_valid_path(t_complete *game);
int			dfs(t_complete *game, char **map, int height, int width);
char		**create_map_copy(char **original_map, int height, int width);
void		free_map_copy(char **map_copy, int height);

int			right_move(t_complete *game, int i, int j);
int			keyboard_w(t_complete *game, int movement);
int			keyboard_s(t_complete *game, int movement);
int			keyboard_a(t_complete *game, int movement);
int			keyboard_d(t_complete *game, int movement);

int			horizontal_check(t_complete *game);
int			vertical_check(t_complete *game);
void		walls_check(t_complete *game);
void		char_check(t_complete *game, int height, int width);

#endif
