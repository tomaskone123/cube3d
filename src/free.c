/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:43:08 by tomas             #+#    #+#             */
/*   Updated: 2025/09/23 14:51:52 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"


int free_array(char** array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

int free_map(t_map *map)
{
	if (map->no_texture)
		free(map->no_texture);
	if (map->so_texture)
		free(map->so_texture);
	if (map->we_texture)
		free(map->we_texture);
	if (map->ea_texture)
		free(map->ea_texture);
	if (map->parsed_file)
		free_array(map->parsed_file);
	if (map->map_grid)
		free_array(map->map_grid);
	free(map);
	return (0);
}

int free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game)
		free(game);
	return (0);
}
