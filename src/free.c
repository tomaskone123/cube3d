/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:43:08 by tomas             #+#    #+#             */
/*   Updated: 2025/10/01 13:35:45 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static void	txt_delete(t_map *map)
{
	if (map->no_mlx_txt)
		mlx_delete_texture(map->no_mlx_txt);
	if (map->so_mlx_txt)
		mlx_delete_texture(map->so_mlx_txt);
	if (map->we_mlx_txt)
		mlx_delete_texture(map->we_mlx_txt);
	if (map->ea_mlx_txt)
		mlx_delete_texture(map->ea_mlx_txt);
}

int	free_map(t_map *map)
{
	if (map->ceiling_color)
		free(map->ceiling_color);
	if (map->floor_color)
		free(map->floor_color);
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
	if (map->flood_grid)
		free_array(map->flood_grid);
	txt_delete(map);
	free(map);
	return (0);
}

int	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	if (game->frame && game->mlx)
		mlx_delete_image(game->mlx, game->frame);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game)
		free(game);
	return (0);
}
