/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:55:12 by tomas             #+#    #+#             */
/*   Updated: 2025/10/09 14:34:33 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

// void	draw_map_2d(t_game *game)
// {
// 	int	tile_size;
// 	int	color;
// 	int	player_size;
// 	int	px;
// 	int	py;
// 	int	draw_x;
// 	int	draw_y;
// 	int	lx;
// 	int	ly;

// 	tile_size = TILE;
// 	// --- Draw map tiles ---
// 	for (int y = 0; y < game->map->height; y++)
// 	{
// 		for (int x = 0; x < game->map->width; x++)
// 		{
// 			color = (game->map->map_grid[y][x] == '1') ? game->map->ceiling_final : game->map->floor_final;
// 			for (int i = 0; i < tile_size; i++)
// 			{
// 				for (int j = 0; j < tile_size; j++)
// 				{
// 					px = x * tile_size + i;
// 					py = y * tile_size + j;
// 					if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
// 						mlx_put_pixel(game->frame, px, py, color);
// 				}
// 			}
// 		}
// 	}
// 	// --- Draw player ---
// 	player_size = PLAYER;
// 	px = (int)(game->player->px * tile_size);
// 	py = (int)(game->player->py * tile_size);
// 	for (int i = -player_size / 2; i < player_size / 2; i++)
// 	{
// 		for (int j = -player_size / 2; j < player_size / 2; j++)
// 		{
// 			draw_x = px + i;
// 			draw_y = py + j;
// 			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
// 				mlx_put_pixel(game->frame, draw_x, draw_y, 0xFF0000FF);
// 		}
// 	}
// 	float line_length = 40.0f; // how far the line goes
// 	for (int i = 0; i < (int)line_length; i++)
// 	{
// 		lx = px + (int)(cos(game->player->angle) * i);
// 		ly = py + (int)(sin(game->player->angle) * i);
// 		if (lx >= 0 && lx < WIDTH && ly >= 0 && ly < HEIGHT)
// 			mlx_put_pixel(game->frame, lx, ly, 0x00FF00FF); // green line
// 	}
// }

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->frame, x, y, game->map->ceiling_final);
			else
				mlx_put_pixel(game->frame, x, y, game->map->floor_final);
			x++;
		}
		y++;
	}
}

void	draw_map_3d(t_game *game)
{
	draw_background(game);
	cast_all_rays(game);
}
