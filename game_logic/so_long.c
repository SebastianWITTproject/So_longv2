/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:02 by prossi            #+#    #+#             */
/*   Updated: 2024/02/10 19:20:53 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;
	printf("hi");
	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	if(!map_reading(&game, argv))
	{
		printf("Error\n");
		printf("Map source issue");
		return (0);
	}
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 30),
			(game.heightmap * 30), "solong");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
