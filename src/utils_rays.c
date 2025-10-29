/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:33:29 by tomas             #+#    #+#             */
/*   Updated: 2025/10/29 11:01:37 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	calc_step_and_side_dist(t_game *game, t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player->px - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->player->px)
			* dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player->py - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->player->py)
			* dda->delta_dist_y;
	}
}

void	perform_dda(t_game *game, t_dda *dda)
{
	game->ray->hit = false;
	while (!game->ray->hit)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			game->ray->hit_vertical = true;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			game->ray->hit_vertical = false;
		}
		if (game->map->map_grid[dda->map_y][dda->map_x] == '1')
			game->ray->hit = true;
	}
}

float	calc_perp_distance(t_game *game, t_dda *dda)
{
	float	perp_dist;

	if (game->ray->hit_vertical)
		perp_dist = (dda->map_x - game->player->px + (1 - dda->step_x) / 2)
			/ dda->ray_dir_x;
	else
		perp_dist = (dda->map_y - game->player->py + (1 - dda->step_y) / 2)
			/ dda->ray_dir_y;
	return (perp_dist);
}

void	calc_wall_bounds(t_game *game, float perp_dist)
{
	int	wall_height;

	wall_height = (int)(HEIGHT / perp_dist);
	game->ray->start = -wall_height / 2 + HEIGHT / 2;
	if (game->ray->start < 0)
		game->ray->start = 0;
	game->ray->end = wall_height / 2 + HEIGHT / 2;
	if (game->ray->end >= HEIGHT)
		game->ray->end = HEIGHT - 1;
}

void	set_wall_direction(t_game *game, t_dda *dda)
{
	if (game->ray->hit_vertical)
	{
		if (dda->ray_dir_x > 0)
			game->ray->wall_dir = 'E';
		else
			game->ray->wall_dir = 'W';
	}
	else
	{
		if (dda->ray_dir_y > 0)
			game->ray->wall_dir = 'S';
		else
			game->ray->wall_dir = 'N';
	}
}
