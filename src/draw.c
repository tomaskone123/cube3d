/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:55:12 by tomas             #+#    #+#             */
/*   Updated: 2025/10/07 10:38:24 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

// void	draw_map_2d(t_game *game)
// {
// 	int i = 0;
// 	while (game->map->map_grid[i])
// 	{
// 		printf("%s\n", game->map->map_grid[i]);
// 		i++;
// 	}
// 	int	color;

// 	int tile_size = 20; // size of each square on screen
// 	for (int y = 0; y < game->map->height; y++)
// 	{
// 		for (int x = 0; x < game->map->width; x++)
// 		{
// 			color = (game->map->map_grid[y][x] == '1') ? 0xFFFFFF : 0x000000;
// 			for (int i = 0; i < tile_size; i++)
// 				for (int j = 0; j < tile_size; j++)
// 					mlx_put_pixel(game->frame, x * tile_size + i, y * tile_size
// 						+ j, color);
// 		}
// 	}
// }

void	draw_map_2d(t_game *game)
{
	int tile_size = 30;
	int color;

	// --- Draw map tiles ---
	for (int y = 0; y < game->map->height; y++)
	{
		for (int x = 0; x < game->map->width; x++)
		{
			color = (game->map->map_grid[y][x] == '1') ? 0xFFFFFFFF : 0x000000FF;
			for (int i = 0; i < tile_size; i++)
			{
				for (int j = 0; j < tile_size; j++)
				{
					int px = x * tile_size + i;
					int py = y * tile_size + j;
					if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
						mlx_put_pixel(game->frame, px, py, color);
				}
			}
		}
	}

	// --- Draw player ---
	int player_size = 10;
	int px = (int)(game->player->px * tile_size);
	int py = (int)(game->player->py * tile_size);
	for (int i = -player_size / 2; i < player_size / 2; i++)
	{
		for (int j = -player_size / 2; j < player_size / 2; j++)
		{
			int draw_x = px + i;
			int draw_y = py + j;
			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
				mlx_put_pixel(game->frame, draw_x, draw_y, 0xFF0000FF);
		}
	}
}

