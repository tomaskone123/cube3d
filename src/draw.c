/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:55:12 by tomas             #+#    #+#             */
/*   Updated: 2025/10/01 14:13:41 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	draw_map_2d(t_game *game)
{
	int i = 0;
	while (game->map->map_grid[i])
	{
		printf("%s", game->map->map_grid[i]);
		i++;
	}
	int	color;

	int tile_size = 20; // size of each square on screen
	for (int y = 0; y < game->map->height; y++)
	{
		for (int x = 0; x < game->map->width; x++)
		{
			color = (game->map->map_grid[y][x] == '1') ? 0xFFFFFF : 0x000000;
			for (int i = 0; i < tile_size; i++)
				for (int j = 0; j < tile_size; j++)
					mlx_put_pixel(game->frame, x * tile_size + i, y * tile_size
						+ j, color);
		}
	}
}
