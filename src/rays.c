/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:45:54 by tomas             #+#    #+#             */
/*   Updated: 2025/10/15 15:55:27 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

// void	cast_ray(t_game *game, float ray_angle)
// {
// 	float	ray_x;
// 	float	ray_y;
// 	float	step;
// 	int		mapx;
// 	int		mapy;
// 	bool	hit;

// 	hit = false;
// 	step = 0.05f;
// 	ray_x = game->player->px;
// 	ray_y = game->player->py;
// 	while (!hit)
// 	{
// 		ray_x += cos(ray_angle) * step;
// 		ray_y += sin(ray_angle) * step;
// 		mapx = (int)ray_x;
// 		mapy = (int)ray_y;
// 		if (game->map->map_grid[mapy][mapx] == '1')
// 			hit = true;
// 		mapx = (int)(ray_x * TILE);
// 		mapy = (int)(ray_y * TILE);
// 		if (mapx >= 0 && mapx < WIDTH && mapy >= 0 && mapy < HEIGHT)
// 			mlx_put_pixel(game->frame, mapx, mapy, 0x00FF00FF);
// 	}
// }

char	get_wall_dir(t_ray *ray, float ray_angle)
{
	float	dist_to_vert;
	float	dist_to_horizont;

	dist_to_vert = fabsf(ray->x - floorf(ray->x));
	dist_to_horizont = fabsf(ray->y - floorf(ray->y));
	if (dist_to_vert < dist_to_horizont)
	{
		if (cos(ray_angle) > 0)
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (sin(ray_angle) > 0)
			return ('S');
		else
			return ('N');
	}
	return ('S');
}

uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	int		index;
	uint8_t	*p;

	index = (y * texture->width + x) * 4;
	p = &texture->pixels[index];
	return (p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
}

void	cast_ray(t_game *game, float ray_angle, int column)
{
	mlx_texture_t	*texture;
	int				mapx;
	int				mapy;
	float			wall_height;
	float			step;
	float			tex_pos;
	int				tex_y;
	uint32_t		color;

	// int				j;
	// j = 0;
	game->ray->hit = false;
	game->ray->step = 1.0f / TILE;
	// game->ray->step = PIXELATION;
	game->ray->x = game->player->px;
	game->ray->y = game->player->py;
	while (!game->ray->hit)
	{
		game->ray->x += cos(ray_angle) * game->ray->step;
		game->ray->y += sin(ray_angle) * game->ray->step;
		mapx = (int)game->ray->x;
		mapy = (int)game->ray->y;
		if (game->map->map_grid[mapy][mapx] == '1')
		{
			game->ray->hit = true;
			game->ray->wall_dir = get_wall_dir(game->ray, ray_angle);
		}
	}
	get_start_end(game, ray_angle);
	texture = get_texture(game);
	if (game->ray->wall_dir == 'E' || game->ray->wall_dir == 'W')
		game->ray->wall_x = game->ray->y - floorf(game->ray->y);
	else
		game->ray->wall_x = game->ray->x - floorf(game->ray->x);
	game->ray->tex_x = (int)(game->ray->wall_x * texture->width);
	wall_height = game->ray->end - game->ray->start;
	step = (float)texture->height / wall_height;
	tex_pos = 0.0f;
	// 4️⃣ Draw textured wall slice
	for (int j = game->ray->start; j < game->ray->end; j++)
	{
		tex_y = (int)tex_pos;
		color = get_texture_color(texture, game->ray->tex_x, tex_y);
		mlx_put_pixel(game->frame, column, j, color);
		tex_pos += step;
	}
	// j = game->ray->start;
	// while (j < game->ray->end)
	// 	mlx_put_pixel(game->frame, column, j++, 0xFFFFFF);
}

void	cast_all_rays(t_game *game)
{
	int		num_rays;
	float	fov;
	float	start_angle;
	float	angle_step;
	int		i;

	num_rays = WIDTH;
	fov = M_PI / 3;
	start_angle = game->player->angle - fov / 2;
	angle_step = fov / num_rays;
	i = 0;
	while (i < WIDTH)
	{
		cast_ray(game, start_angle + i * angle_step, i);
		i++;
	}
}
