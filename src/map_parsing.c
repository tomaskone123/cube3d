/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:26:31 by tomas             #+#    #+#             */
/*   Updated: 2025/09/25 15:49:07 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static int	is_map_values(char **line, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			while (is_space(line[i][j]))
				j++;
			if (line[i][j] != '1' && line[i][j] != '0' && line[i][j] != 'N'
				&& line[i][j] != 'S' && line[i][j] != 'E' && line[i][j] != 'W'
				&& !is_space(line[i][j]))
				return (0);
			j++;
		}
		game->map->map_grid[i] = ft_strdup(line[i]);
		ft_printf("%s\n", game->map->map_grid[i]);
		i++;
	}
	game->map->height = i;
	return (1);
}

static void	find_player(t_game *game)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (game->map->map_grid[i])
	{
		j = 0;
		while (game->map->map_grid[i][j])
		{
			if (game->map->map_grid[i][j] == 'N'
				|| game->map->map_grid[i][j] == 'S'
				|| game->map->map_grid[i][j] == 'E'
				|| game->map->map_grid[i][j] == 'W')
			{
				found++;
				game->map->player_x = j;
				game->map->player_y = i;
				game->map->player_dir = game->map->map_grid[i][j];
			}
		}
		i++;
	}
	if ((found > 1) || (found <= 0))
		error_exit(PLAYER_COUNT, game);
}

void	get_map(t_game *game)
{
	int	size;

	size = array_size(game->map->parsed_file + 6);
	game->map->map_grid = ft_calloc(size + 1, sizeof(char *));
	if (!is_map_values(game->map->parsed_file + 6, game))
		error_exit(MAP_VALUES_WRONG, game);
	find_player(game);
}
