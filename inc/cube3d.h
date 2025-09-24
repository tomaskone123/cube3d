/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:34:12 by tomas             #+#    #+#             */
/*   Updated: 2025/09/24 10:54:17 by tomas            ###   ########.fr       */
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

typedef struct	s_map
{
	int			fd;

	char		**parsed_file;
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

	char*		floor_color;
	char*		ceiling_color;
}				t_map;

typedef struct	s_txt_array
{
	char *id;
	char **texture;
}				t_txt_array;

typedef struct	s_game
{
	mlx_t		*mlx;
	t_map		*map;
}				t_game;

// ERROR HANDELING
void error_exit(char *error_message, t_game *game);

// FREEING FUNCTION
int free_game(t_game *game);



// PARSER
void	parser(t_game *game);
int	argument_check(char *map_argument, int argc, t_game *game);
void	check_duplicates(t_game* game);
int		get_textures(t_game *game);


// UTILS
int	file_exists(char *file_path, char* extention, t_game *game);
int	space_increment(char* string, int number);
int	is_space(char value);


#endif
