/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:34:12 by tomas             #+#    #+#             */
/*   Updated: 2025/09/25 12:43:42 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define CUB ".cub"
# define PNG ".png"

# define MALOC_FAIL_PARSE_FILE "Couldn't allocate memory for the 'file_content' variable"
# define MALOC_FAIL_GAME "Couldn't allocate memory for the 'game' struct"
# define ARGUMENT_NUMBER_FAIL "The number of argluments needed is 1"
# define EXTENTION_CUB_FAIL "The map file type is not .cub"
# define EXTENTION_PNG_FAIL "The map file type is not .png"
# define FAIL_OPEN_FILE "The map file failed to open"
# define MALOC_FAIL_MAP "Couldn't allocate memory for the 'map' struct"
# define MISSING_VALUE "Value is missing in the map file"
# define DUP_VALUE "There is a duplicate in the map file"
# define MALOC_FAIL_TEXTURE "Couldn't allocate memory for the texture variable"
# define MALOC_FAIL_COLOUR "Couldn't allocate memory for the clour variable"
# define TXT_LOAD_FAIL "One of the textures failed to load"
# define CLR_WRONG_NUMBER "The color is not number"
# define CLR_NOT_ENOUGH "Wrong format of color\n(Needs to be 0-255 as R,G,B) :^)"
# define MAP_VALUES_WRONG "Wrong values in the map"

typedef struct s_map
{
	int				fd;

	char			**parsed_file;
	char			**map_grid;

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

typedef struct s_txt_array
{
	char			*id;
	char			**texture;
}					t_txt_array;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			*map;
}					t_game;

// ERROR HANDELING
void				error_exit(char *error_message, t_game *game);

// FREEING FUNCTION
int					free_game(t_game *game);
int					free_array(char **array);

// PARSER
void				parser(t_game *game);
int					argument_check(char *map_argument, int argc, t_game *game);
void				check_duplicates(t_game *game);
int					get_textures_and_colors(t_game *game);
int					color_convert(char *color, t_game *game);
void				get_map(t_game* game);

// UTILS
int					file_exists(char *file_path, char *extention, t_game *game);
int					space_increment(char *string, int number);
int					is_space(char value);
int					array_size(char **array);

#endif
