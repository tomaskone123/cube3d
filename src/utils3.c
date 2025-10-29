/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:52:26 by tomas             #+#    #+#             */
/*   Updated: 2025/10/29 09:32:15 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	get_start_end(t_game *game, float ray_angle)
{
	// calculate distance from wall
	game->ray->distance = sqrt((game->ray->x - game->player->px) * (game->ray->x
			- game->player->px) + (game->ray->y - game->player->py)
		* (game->ray->y - game->player->py));
	// fix fisheye lens
	game->ray->distance *= cos(ray_angle - game->player->angle);
	if (game->ray->distance < 0.0001f)
		game->ray->distance = 0.0001f;
	game->ray->wall_height = HEIGHT / game->ray->distance;
	game->ray->start = (HEIGHT - game->ray->wall_height) / 2;
	game->ray->end = (HEIGHT + game->ray->wall_height) / 2;
	// keep values within boundries after deviding
	if (game->ray->start < 0)
		game->ray->start = 0;
	if (game->ray->end >= HEIGHT)
		game->ray->end = HEIGHT - 1;
}


mlx_texture_t	*get_texture(t_game *game)
{
	if (game->ray->wall_dir == 'S')
		return (game->map->so_mlx_txt);
	else if (game->ray->wall_dir == 'N')
		return (game->map->no_mlx_txt);
	else if (game->ray->wall_dir == 'W')
		return (game->map->we_mlx_txt);
	else
		return (game->map->ea_mlx_txt);
}

void	init_dda(t_game *game, float ray_angle, t_dda *dda)
{
	dda->ray_dir_x = cos(ray_angle);
	dda->ray_dir_y = sin(ray_angle);
	dda->map_x = (int)game->player->px;
	dda->map_y = (int)game->player->py;
	dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
}
