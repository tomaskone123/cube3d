/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:26:31 by tomas             #+#    #+#             */
/*   Updated: 2025/09/25 13:18:27 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static int	is_map_values(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (is_space(line[i]))
			i++;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && !is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_map(t_game *game)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	i = 7;
	size = array_size(game->map->parsed_file + 7);
	game->map->map_grid = ft_calloc(size + 1, sizeof(char*));
	while (game->map->parsed_file[i])
	{
		if (!is_map_values(game->map->parsed_file[i]))
			error_exit(MAP_VALUES_WRONG, game);
		game->map->map_grid[j] = ft_strdup(game->map->parsed_file[i]);
		i++;
		j++;
	}
	i = 0;
	while (game->map->map_grid[i])
	{
		printf("%s\n", game->map->map_grid[i]);
		i++;
	}
}
