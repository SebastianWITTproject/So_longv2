/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:27:57 by switt             #+#    #+#             */
/*   Updated: 2024/02/04 20:23:35 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
#include "get_next_line.h"
# include "sl_keys.h"

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	int player_x;
	int player_y;
	int coll_count;
	char **map;
}	t_data;

char	*ft_strdup(const char *src);
char	**ft_split(char *str, char c);
void r_player(t_data *data, int x_pos, int y_pos);
void r_wall(t_data *data, int x_pos, int y_pos);
void r_floor(t_data *data, int x_pos, int y_pos);
void r_coll(t_data *data, int x_pos, int y_pos);
void r_door(t_data *data, int x_pos, int y_pos);
char	*ft_strjoinbis(char  *s1, char  *s2);

void moveup(t_data *data);
void moveleft(t_data *data);
void moveright(t_data *data);
void movedown(t_data *data);

void renderbg (t_data *data);
int isvalidmove(t_data *data, int x, int y);
#endif
