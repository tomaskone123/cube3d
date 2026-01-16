/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:26:31 by tomas             #+#    #+#             */
/*   Updated: 2026/01/16 14:45:38 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	flood_fill(t_game *game, int y, int x, char **visited)
{
	char	c;

	if (y < 0 || y >= game->map->height || x < 0
		|| x >= (int)ft_strlen(visited[y]))
		return (0);
	c = visited[y][x];
	if (c == '1' || c == 'V')
		return (1);
	if (c == ' ')
		return (0);
	visited[y][x] = 'V';
	if (!flood_fill(game, y - 1, x, visited))
		return (0);
	if (!flood_fill(game, y + 1, x, visited))
		return (0);
	if (!flood_fill(game, y, x - 1, visited))
		return (0);
	if (!flood_fill(game, y, x + 1, visited))
		return (0);
	return (1);
}

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
				error_exit(MAP_VALUES_WRONG, game);
			find_player(game, line[i][j], i, j);
			j++;
		}
		assign_map_variable(game, line, i);
		i++;
	}
	if ((game->map->found > 1) || (game->map->found <= 0))
		error_exit(PLAYER_COUNT, game);
	game->map->height = i;
	return (1);
}

void	normalize_map(t_game *game)
{
	int		i;
	char	*new_line;

	i = 0;
	get_max_width(game, game->map->map_grid, game->map->height);
	while (i < game->map->height)
	{
		new_line = malloc(game->map->width + 1);
		if (!new_line)
			error_exit(MALOC_FAIL_MAP_NL, game);
		fill_map(game, new_line, i);
		i++;
	}
}

void	get_map(t_game *game)
{
	int	size;

	size = array_size(game->map->parsed_file + 6);
	game->map->map_grid = ft_calloc(size + 1, sizeof(char *));
	game->map->flood_grid = ft_calloc(size + 1, sizeof(char *));
	if (!game->map->map_grid || !game->map->flood_grid)
		error_exit(MALOC_FAIL_MAP_GRID, game);
	is_map_values(game->map->parsed_file + 6, game);
	if (!flood_fill(game, game->map->player_y, game->map->player_x,
			game->map->flood_grid))
		error_exit(MAP_NOT_CLOSED, game);
	normalize_map(game);
}
