/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:28:57 by tomas             #+#    #+#             */
/*   Updated: 2025/10/29 11:09:27 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	calc_texture_x(t_game *game, t_dda *dda, float perp_dist,
		mlx_texture_t *texture)
{
	float	hit_x;
	float	hit_y;

	hit_x = game->player->px + perp_dist * dda->ray_dir_x;
	hit_y = game->player->py + perp_dist * dda->ray_dir_y;
	if (game->ray->hit_vertical)
		game->ray->wall_x = hit_y - floor(hit_y);
	else
		game->ray->wall_x = hit_x - floor(hit_x);
	game->ray->tex_x = (int)(game->ray->wall_x * texture->width);
	if (game->ray->tex_x < 0)
		game->ray->tex_x = 0;
	if (game->ray->tex_x >= (int)texture->width)
		game->ray->tex_x = texture->width - 1;
}

uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	int		index;
	uint8_t	*p;

	if (x < 0)
		x = 0;
	if (x >= (int)texture->width)
		x = texture->width - 1;
	if (y < 0)
		y = 0;
	if (y >= (int)texture->height)
		y = texture->height - 1;
	index = (y * texture->width + x) * 4;
	p = &texture->pixels[index];
	return (p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
}

void	draw_wall_column(t_game *game, mlx_texture_t *texture, int column,
		float perp_dist)
{
	int			wall_height;
	float		step;
	float		tex_pos;
	int			tex_y;
	uint32_t	color;

	if (perp_dist <= 0.0001f)
		perp_dist = 0.0001f;
	wall_height = (int)(HEIGHT / perp_dist);
	step = (float)texture->height / wall_height;
	tex_pos = (game->ray->start - (-wall_height / 2 + HEIGHT / 2)) * step;
	game->j = game->ray->start;
	while (game->j < game->ray->end)
	{
		if (game->j >= 0 && game->j < HEIGHT)
		{
			tex_y = ((int)tex_pos % texture->height + texture->height)
				% texture->height;
			tex_pos += step;
			color = get_texture_color(texture, game->ray->tex_x, tex_y);
			mlx_put_pixel(game->frame, column, game->j, color);
		}
		game->j++;
	}
}

void	cast_ray(t_game *game, float ray_angle, int column)
{
	t_dda			dda;
	float			perp_dist;
	mlx_texture_t	*texture;

	init_dda(game, ray_angle, &dda);
	calc_step_and_side_dist(game, &dda);
	perform_dda(game, &dda);
	perp_dist = calc_perp_distance(game, &dda);
	calc_wall_bounds(game, perp_dist);
	set_wall_direction(game, &dda);
	texture = get_texture(game);
	calc_texture_x(game, &dda, perp_dist, texture);
	draw_wall_column(game, texture, column, perp_dist);
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
