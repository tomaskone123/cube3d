/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:34:12 by tomas             #+#    #+#             */
/*   Updated: 2025/09/04 15:16:51 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# define MALOC_FAIL_GAME "Couldn't allocate memory for the 'game' struct"
# define ARGUMENT_NUMBER_FAIL "The number of argluments needed is 1"
# define ARGUMENT_TYPE_FAIL "The map file type is not .cub"
# define FAIL_OPEN_FILE "The map file failed to open"

typedef struct	s_map
{
	int			fd;

	char		**map_grid;

	int			width;
	int			height;

	int			player_x;
	int			player_y;
	char		player_dir;

	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;

	int			floor_color;
	int			ceiling_color;
}				t_map;


typedef struct	s_game
{
	mlx_t		*mlx;
	t_map		*map;
}				t_game;

void error_exit(char *error_message, t_game *game);
int free_game(t_game *game);
int	argument_check(char *argv[], int argc, t_game *game);

#endif
