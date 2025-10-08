/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:55:12 by tomas             #+#    #+#             */
/*   Updated: 2025/10/08 10:58:01 by tomas            ###   ########.fr       */
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
	int	tile_size;
	int	color;
	int	player_size;
	int	px;
	int	py;
	int	draw_x;
	int	draw_y;

	tile_size = 40;
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
					px = x * tile_size + i;
					py = y * tile_size + j;
					if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
						mlx_put_pixel(game->frame, px, py, color);
				}
			}
		}
	}
	// --- Draw player ---
	player_size = 15;
	px = (int)(game->player->px * tile_size);
	py = (int)(game->player->py * tile_size);
	for (int i = -player_size / 2; i < player_size / 2; i++)
	{
		for (int j = -player_size / 2; j < player_size / 2; j++)
		{
			draw_x = px + i;
			draw_y = py + j;
			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
				mlx_put_pixel(game->frame, draw_x, draw_y, 0xFF0000FF);
		}
	}
	float line_length = 40.0f; // how far the line goes
	for (int i = 0; i < (int)line_length; i++)
	{
		int lx = px + (int)(cos(game->player->angle) * i);
		int ly = py + (int)(sin(game->player->angle) * i);
		if (lx >= 0 && lx < WIDTH && ly >= 0 && ly < HEIGHT)
			mlx_put_pixel(game->frame, lx, ly, 0x00FF00FF); // green line
	}
}

void	rotate_player(t_player *player, mlx_key_data_t keydata)
{
	float	rot_spead;

	rot_spead = 0.1f;
	if (keydata.key == MLX_KEY_RIGHT)
		player->angle += rot_spead;
	else if (keydata.key == MLX_KEY_LEFT)
		player->angle -= rot_spead;
	// keep angle between 0 and 2π
	if (player->angle < 0)
		player->angle += 2 * M_PI;
	else if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	player->dirx = cos(player->angle);
	player->diry = sin(player->angle);
}

void	try_move(t_game *game, float dx, float dy)
{
	float	new_x;
	float	new_y;

	new_x = game->player->px + dx;
	new_y = game->player->py + dy;
	if (game->map->map_grid[(int)new_y][(int)new_x] != '1')
	{
		game->player->px = new_x;
		game->player->py = new_y;
	}
}
