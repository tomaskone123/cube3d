/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:52:26 by tomas             #+#    #+#             */
/*   Updated: 2025/10/15 15:47:54 by tomas            ###   ########.fr       */
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
