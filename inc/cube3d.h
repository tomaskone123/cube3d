/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:34:12 by tomas             #+#    #+#             */
/*   Updated: 2025/11/18 17:59:37 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define CUB ".cub"
# define PNG ".png"

# define WIDTH 1800
# define HEIGHT 1200
# define TILE 50
# define PLAYER 10
# define PLAYER_SPEED 0.06f
# define ROTATION_SPEED 0.1f
# define PIXELATION 0.04f
# define M_PI 3.14159265358979323846

# define MALOC_FAIL_RAY_STR "Couldn't allocate memory for the 'ray' struct"
# define MALOC_FAIL_PARSE_FILE "Couldn't allocate memory for the 'file_content'"
# define MALOC_FAIL_GAME "Couldn't allocate memory for the 'game' struct"
# define ARGUMENT_NUMBER_FAIL "The number of argluments needed is 1"
# define EXTENTION_CUB_FAIL "The map file type is not .cub"
# define EXTENTION_PNG_FAIL "The map file type is not .png"
# define FAIL_OPEN_FILE "The map file failed to open"
# define MALOC_FAIL_MAP "Couldn't allocate memory for the 'map' struct"
# define MALOC_FAIL_PLAYER "Couldn't allocate memory for the 'player' struct"
# define MISSING_VALUE "Value is missing in the map file"
# define DUP_VALUE "There is a duplicate in the map file"
# define MALOC_FAIL_TEXTURE "Couldn't allocate memory for the texture variable"
# define MALOC_FAIL_COLOUR "Couldn't allocate memory for the clour variable"
# define TXT_LOAD_FAIL "One of the textures failed to load"
# define CLR_WRONG_NUMBER "The color is not number"
# define CLR_NOT_ENOUGH "Wrong format of color"
# define MAP_VALUES_WRONG "Wrong values in the map"
# define PLAYER_COUNT "Wrong amount of players"
# define MALOC_FAIL_MAP_NL "Couldn't allocate memory in normalize_map"
# define MALOC_FAIL_MAP_GRID "Couldn't allocate memory for the 'map_grid'"
# define MALOC_FAIL_VISITED "Couldn't allocate memory for the 'visited'"
# define MAP_NOT_CLOSED "The map is not enclosed in walls"
# define NEW_FRAME_FAIL "Failed to load the new frame"

typedef struct s_dda
{
	float			ray_dir_x;
	float			ray_dir_y;
	int				map_x;
	int				map_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			side_dist_x;
	float			side_dist_y;
	int				step_x;
	int				step_y;
}					t_dda;

typedef struct s_map
{
	int				fd;
	int				found;

	char			**parsed_file;
	char			**map_grid;
	char			**flood_grid;

	int				width;
	int				height;

	int				player_x;
	int				player_y;
	char			player_dir;

	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	mlx_texture_t	*no_mlx_txt;
	mlx_texture_t	*so_mlx_txt;
	mlx_texture_t	*we_mlx_txt;
	mlx_texture_t	*ea_mlx_txt;

	char			*floor_color;
	char			*ceiling_color;
	uint32_t		ceiling_final;
	uint32_t		floor_final;
}					t_map;

typedef struct s_player
{
	float			px;
	float			py;
	float			dirx;
	float			diry;
	float			angle;
}					t_player;

typedef struct s_txt_array
{
	char			*id;
	char			**texture;
}					t_txt_array;

typedef struct s_ray
{
	float			x;
	float			y;
	float			step;
	bool			hit;
	bool			hit_vertical;
	float			distance;
	int				wall_height;
	char			wall_dir;
	float			wall_x;
	int				tex_x;
	int				start;
	int				end;
}					t_ray;

typedef struct s_game
{
	int				j;
	t_player		*player;
	mlx_image_t		*frame;
	mlx_t			*mlx;
	t_map			*map;
	t_ray			*ray;
}					t_game;

// ERROR HANDELING
void				error_exit(const char *error_message, t_game *game);

// FREEING FUNCTION
int					free_game(t_game *game);
int					free_array(char **array);

// PARSER
void				parser(t_game *game);
int					argument_check(char *map_argument, int argc, t_game *game);
void				check_duplicates(t_game *game);
int					get_textures_and_colors(t_game *game);
int					color_convert(char *color, t_game *game);
void				get_map(t_game *game);

// UTILS
int					file_exists(char *file_path, char *extention, t_game *game);
int					space_increment(char *string, int number);
int					is_space(char value);
int					array_size(char **array);
void				get_max_width(t_game *game, char **map, int height);
void				fill_map(t_game *game, char *new_line, int i);
void				find_player(t_game *game, char value, int i, int j);
void				assign_map_variable(t_game *game, char **line, int i);
void				get_player_dir(t_game *game);
void				get_start_end(t_game *game, float ray_angle);
mlx_texture_t		*get_texture(t_game *game);
void				init_dda(t_game *game, float ray_angle, t_dda *dda);

// RAYS_UTILS
void				set_wall_direction(t_game *game, t_dda *dda);
void				calc_wall_bounds(t_game *game, float perp_dist);
float				calc_perp_distance(t_game *game, t_dda *dda);
void				perform_dda(t_game *game, t_dda *dda);
void				calc_step_and_side_dist(t_game *game, t_dda *dda);

// // TEST
// void				draw_map_2d(t_game *game);

// MOVEMENT
void				rotate_player(t_game *game);
void				try_move(t_game *game, float dx, float dy);
void				move_player(t_game *game);

// GAME LOOP
void				run_game(t_game *game);

// RAYS
void				cast_all_rays(t_game *game);

// DRAW
void				draw_map_3d(t_game *game);

#endif
