#include "so_long.h"


void moveup(t_data *data)
{
    if (isvalidmove(data, data->player_x - 1, data->player_y ))
    {
   data->map[data->player_x][data->player_y] = '0';
    data->player_x = data->player_x - 1;
   data->map[data->player_x][data->player_y] = 'P';
    renderbg(data);
    }
}

void moveleft(t_data *data)
{
    if (isvalidmove(data, data->player_x , data->player_y - 1 ))
    {
   data->map[data->player_x][data->player_y] = '0';
    data->player_y = data->player_y - 1;
   data->map[data->player_x][data->player_y] = 'P';
    renderbg(data);
    }
}

void moveright(t_data *data)
{
    if (isvalidmove(data, data->player_x , data->player_y + 1 ))
    {
   data->map[data->player_x][data->player_y] = '0';
    data->player_y = data->player_y + 1;
   data->map[data->player_x][data->player_y] = 'P';
    renderbg(data);
    }
}

void movedown(t_data *data)
{
   if (isvalidmove(data, data->player_x + 1, data->player_y ))
   {
   data->map[data->player_x][data->player_y] = '0';
    data->player_x = data->player_x + 1;
   data->map[data->player_x][data->player_y] = 'P';
    renderbg(data);
   }
}