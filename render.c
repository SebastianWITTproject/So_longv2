#include "so_long.h"

void r_player(t_data *data, int x_pos, int y_pos)
{
    int w = 30;
    int h = 30;
    char *img_ptr;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player.xpm", &w, &h);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x_pos, y_pos);
}

void r_wall(t_data *data, int x_pos, int y_pos)
{
    int w = 30;
    int h = 30;
    char *img_ptr;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall.xpm", &w, &h);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x_pos, y_pos);
}

void r_floor(t_data *data, int x_pos, int y_pos)
{
    int w = 30;
    int h = 30;
    char *img_ptr;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor.xpm", &w, &h);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x_pos, y_pos);
}

void r_coll(t_data *data, int x_pos, int y_pos)
{
    int w = 30;
    int h = 30;
    char *img_ptr;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "assets/coll.xpm", &w, &h);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x_pos, y_pos);
}

void r_door(t_data *data, int x_pos, int y_pos)
{
    int w = 30;
    int h = 30;
    char *img_ptr;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "assets/door.xpm", &w, &h);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x_pos, y_pos);
}