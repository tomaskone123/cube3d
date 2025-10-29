/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:29:30 by tomas             #+#    #+#             */
/*   Updated: 2025/10/23 10:18:01 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	rotate_player(t_game *game)
{
	float	rot_spead;

	rot_spead = ROTATION_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player->angle += rot_spead;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player->angle -= rot_spead;
	if (game->player->angle < 0)
		game->player->angle += 2 * M_PI;
	else if (game->player->angle > 2 * M_PI)
		game->player->angle -= 2 * M_PI;
	game->player->dirx = cos(game->player->angle);
	game->player->diry = sin(game->player->angle);
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

void	move_player(t_game *game)
{
	float	move_speed;
	float	sidex;
	float	sidey;

	sidex = -game->player->diry;
	sidey = game->player->dirx;
	move_speed = PLAYER_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		try_move(game, game->player->dirx * move_speed, game->player->diry
			* move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		try_move(game, -game->player->dirx * move_speed, -game->player->diry
			* move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		try_move(game, sidex * move_speed, sidey * move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		try_move(game, -sidex * move_speed, -sidey * move_speed);
	rotate_player(game);
}
