/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:40:20 by tomas             #+#    #+#             */
/*   Updated: 2025/10/08 10:17:24 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	move_player(t_game *game, mlx_key_data_t keydata)
{
	float	move_speed;
	float	new_px;
	float	new_py;

	move_speed = 0.1f;
	new_px = game->player->px;
	new_py = game->player->py;
	if (keydata.key == MLX_KEY_W)
		new_py -= move_speed;
	else if (keydata.key == MLX_KEY_S)
		new_py += move_speed;
	else if (keydata.key == MLX_KEY_A)
		new_px -= move_speed;
	else if (keydata.key == MLX_KEY_D)
		new_px += move_speed;
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
		rotate_player(game->player, keydata);
	if (new_py >= 0 && new_py < game->map->height && new_px >= 0
		&& new_px < game->map->width
		&& game->map->map_grid[(int)new_py][(int)new_px] != '1')
	{
		game->player->px = new_px;
		game->player->py = new_py;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;
	t_game	*game;

	game = param;
	mlx = game->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	else
		move_player(game, keydata);
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
	
	if (game->frame)
		mlx_delete_image(game->mlx, game->frame);
	game->frame = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->frame)
	{
		mlx_close_window(game->mlx);
		error_exit(NEW_FRAME_FAIL, game);
	}
	draw_map_2d(game);
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
