#include "so_long.h"

int	horizontal_check(t_complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (!(game->map[0][j] == '1' && game->map[game->heightmap
				- 1][j] == '1'))
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	vertical_check(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (game->map[height][0] != '1' || game->map[height][width - 1] != '1')
		{
			return (0);
		}
		height++;
	}
	return (1);
}

void	walls_check(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = vertical_check(game);
	horizontalwalls = horizontal_check(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("Error\n");
		printf("\nMap content is invalid1\n");
		exit_point(game);
	}
}

void	char_check(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' && game->map[height][width] != '0'
		&& game->map[height][width] != 'P' && game->map[height][width] != 'E'
		&& game->map[height][width] != 'C' && game->map[height][width] != '\n')
	{
		printf("Error\n");
		printf("Map content is invalid2\n");
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}
