/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuik <skuik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:55:12 by tomas             #+#    #+#             */
/*   Updated: 2026/01/16 12:20:36 by skuik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
