#include "so_long.h"
#include "mlx/mlx.h"

int on_keypress(int key, t_data *data)
{

	(void)data;
	printf("Pressed key: %d\\n", key);
	if (key == K_W || key == K_UP)
	moveup(data);
	if (key == K_S || key == K_DOWN)
	movedown(data);
	if (key == K_A || key == K_LEFT)
	moveleft(data);
	if (key == K_D || key == K_RIGHT)
	moveright(data);
	return (0);
}

void getbginfo(t_data *data)
{
	int i = 0;
	int j = 0;
	data->coll_count = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
			}
			if (data->map[i][j] == 'C')
			{
				data->coll_count = data->coll_count + 1;
			}
			j ++;
		}
		j = 0;
		i ++;
	}
}

void init_render (t_data *data)
{
	
	int i = 0;
	int j = 0;
	int x_pos = 0;
	int y_pos = 0;
	
	while (data->map[i])
	{
		while (data->map[i][j])
		{
				if (data->map[i][j] != '1')
				r_floor(data, x_pos, y_pos);
			x_pos += 30;
			j ++;
		}
			x_pos = 0;
			j = 0;
			y_pos +=30;
			i ++;

	}
}
void renderbg (t_data *data)
{
	int i = 0;
	int j = 0;
	int x_pos = 0;
	int y_pos = 0;
	
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				r_floor(data, x_pos, y_pos);
			if (data->map[i][j] == '1')
				r_wall(data, x_pos, y_pos);
			if (data->map[i][j] == 'P')
				r_player(data, x_pos, y_pos);
			if (data->map[i][j] == 'C')
				r_coll(data, x_pos, y_pos);
			if (data->map[i][j] == 'E')
				r_door(data, x_pos, y_pos);
			x_pos += 30;
			j ++;
		}
			x_pos = 0;
			j = 0;
			y_pos +=30;
			i ++;

	}

}

char *init_string()
{	
	char *line;
	int fd;
	char *joined_line;
	joined_line = ft_strdup("");
	line = "";
	fd = open("map.ber", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_line = ft_strjoinbis(joined_line, line);
		free(line);
	}
	return joined_line;
}

int main(void)
{
	t_data data;
	char *map_string;
	char **map_final;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	map_string = init_string();
	map_final = ft_split(map_string, '\n');
	data.map = map_final;
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	init_render(&data);
	renderbg(&data);
	getbginfo(&data);
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, 2, 0, &on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}