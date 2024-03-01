#include "so_long.h"

// Modify character_valid to use the new is_valid_path function
void valid_path(t_complete *game)
{
    // Initialize variables for tracking collectibles and exit

    // Call is_valid_path with initial values
    if (!is_valid_path(game))
    {
        printf("\nError\nNo valid path found!\n");
        exit_point(game);
        // Exit or handle the error accordingly
    }
}

// Check if there is a valid path from the player to each collectible and from each collectible to the exit
int is_valid_path(t_complete *game)
{
    // Find the player's position
    int playerHeight = 0;
    int playerWidth = 0;
    int pos_x = 0;
    int pos_y = 0;

    char **map_cpy = create_map_copy(game->map, game->heightmap, game->widthmap);

    game->collectibles_collected = 0;

    // Use while loops instead of for loops
    while (playerHeight < game->heightmap)
    {
        playerWidth = 0;
        while (playerWidth < game->widthmap)
        {
            if (map_cpy[playerHeight][playerWidth] == 'P')
            {
                // Break out of both while loops when the player is found
                pos_x = playerHeight;
                pos_y = playerWidth;
                break;
            }
            playerWidth++;
        }
        playerHeight++;
    }
    game->player_x = pos_x;
    game->player_y = pos_y;

    // Perform DFS from the player's position
    int result = dfs(game, map_cpy, pos_x, pos_y);

    // Free the memory allocated for the map copy
    free_map_copy(map_cpy, game->heightmap);

    return result;
}

int dfs(t_complete *game, char **map, int height, int width)
{
    if (map[height][width] == '1' || map[height][width] == 'X')
        return 0;

    char current_char = map[height][width];

    if (current_char == 'E')
    {
        game->exit_reached = 1;
    }

    if (current_char == 'C')
    {
        game->collectibles_collected++;
    }

    map[height][width] = 'X';

    dfs(game, map, height + 1, width);
    dfs(game, map, height - 1, width);
    dfs(game, map, height, width + 1);
    dfs(game, map, height, width - 1);

    if (game->collectibles_collected == game->columncount && game->exit_reached == 1)
        return 1;
    return 0;
}

// Function to create a copy of the map
char **create_map_copy(char **original_map, int height, int width)
{
    char **map_copy = malloc(height * sizeof(char *));
    int i = 0;
    while (i < height)
    {
        map_copy[i] = malloc(width * sizeof(char));
        int j = 0;
        while (j < width)
        {
            map_copy[i][j] = original_map[i][j];
            j++;
        }
        i++;
    }
    return map_copy;
}

// Function to free the memory allocated for the map copy
void free_map_copy(char **map_copy, int height)
{
    int i = 0;
    while (i < height)
    {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
}