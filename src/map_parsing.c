/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:26:31 by tomas             #+#    #+#             */
/*   Updated: 2025/09/25 15:12:02 by tomas            ###   ########.fr       */
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

void	get_map(t_game *game)
{
	int	size;

	size = array_size(game->map->parsed_file + 6);
	game->map->map_grid = ft_calloc(size + 1, sizeof(char *));
	if (!is_map_values(game->map->parsed_file + 6, game))
		error_exit(MAP_VALUES_WRONG, game);
}
