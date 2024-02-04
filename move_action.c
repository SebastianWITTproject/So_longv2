#include "so_long.h"

int isvalidmove(t_data *data, int x, int y)
{
    if(data->map[x][y] == '1')
    {
        return (0);
    }
     if(data->map[x][y] == 'E' && data->coll_count > 0)
    {
        return (0);
    }

    return (1);
}