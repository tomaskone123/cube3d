/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:50:54 by tomas             #+#    #+#             */
/*   Updated: 2025/10/07 14:50:08 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	get_max_width(t_game *game, char **map, int height)
{
	size_t	max;
	int		i;

	i = 0;
	max = 0;
	while (i < height)
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	game->map->width = max;
}

void	fill_map(t_game *game, char *new_line, int i)
{
	int	j;

	j = 0;
	while (game->map->map_grid[i][j])
	{
		if (game->map->map_grid[i][j] == ' ')
			new_line[j] = '1';
		else
			new_line[j] = game->map->map_grid[i][j];
		j++;
	}
	while (j < game->map->width)
	{
		new_line[j] = '1';
		j++;
	}
	new_line[j] = '\0';
	free(game->map->map_grid[i]);
	game->map->map_grid[i] = new_line;
}

void	find_player(t_game *game, char value, int i, int j)
{
	if (value == 'N' || value == 'S' || value == 'E' || value == 'W')
	{
		game->map->player_x = j;
		game->map->player_y = i;
		game->map->player_dir = value;
		game->map->found++;
	}
}

void	assign_map_variable(t_game *game, char **line, int i)
{
	game->map->map_grid[i] = ft_strdup(line[i]);
	game->map->flood_grid[i] = ft_strdup(line[i]);
}

void	get_player_dir(t_game *game)
{
	if (game->map->player_dir == 'N')
		game->player->angle = M_PI / 2;
	else if (game->map->player_dir == 'S')
		game->player->angle = 3 * M_PI / 2;
	else if (game->map->player_dir == 'E')
		game->player->angle = 0;
	else if (game->map->player_dir == 'W')
		game->player->angle = M_PI;
	game->player->dirx = cos(game->player->angle);
	game->player->dirx = sin(game->player->angle);
}
