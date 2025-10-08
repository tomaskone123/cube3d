/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:40:20 by tomas             #+#    #+#             */
/*   Updated: 2025/10/08 14:45:20 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;
	t_game	*game;

	game = param;
	mlx = game->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

void	init_game_loop(t_game *game)
{
	game->player->px = (float)game->map->player_x;
	game->player->py = (float)game->map->player_y;
	get_player_dir(game);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
		error_exit(mlx_strerror(mlx_errno), game);
	game->frame = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->frame)
	{
		mlx_close_window(game->mlx);
		error_exit(mlx_strerror(mlx_errno), game);
	}
	if (mlx_image_to_window(game->mlx, game->frame, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		error_exit(mlx_strerror(mlx_errno), game);
	}
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_player(game);
	if (game->frame)
		mlx_delete_image(game->mlx, game->frame);
	game->frame = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->frame)
	{
		mlx_close_window(game->mlx);
		error_exit(NEW_FRAME_FAIL, game);
	}
	draw_map_2d(game);
	cast_all_rays(game);
	if (mlx_image_to_window(game->mlx, game->frame, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		error_exit(NEW_FRAME_FAIL, game);
	}
}

void	run_game(t_game *game)
{
	init_game_loop(game);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
}
