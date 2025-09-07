/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:08:57 by tomas             #+#    #+#             */
/*   Updated: 2025/09/07 19:20:33 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"


// LIST OF STUFF I NEED FOR PARSING
/*
	Except for the map element all of the content can be separated by empty lines
	The content CAN be in any order in the file
	Exept for the map all of the elements CAN be separated by spaces
	- No duplicates or missing of texture and color
		NO
		SO
		WE
		EA
		F
		C
	- File paths for the textures need to exist and be openable in the right format
	- Color format must be in R, G, B.
		Each value 0-2555
		no extra commas or other characters
	MAP:
	- Must exist
	- needs to exist after the texture/color definition
	- only needs to contain the valid characters
		0, 1, N, S, E, W, ' '(space characters for padding)
	- only one character in the map
	- MUST be inclosed by walls
	-
*/

static char	**ft_split_special(char* file_content)
{
	
}

static void	parse_file(t_game *game)
{
	char	*line;
	char	*file_content;
	char	*temp;

	file_content = ft_strdup("");
	if (!file_content)
		error_exit(MALOC_FAIL_PARSE_FILE, game);
	line = get_next_line(game->map->fd);
	while (line)
	{
		temp = ft_strjoin(file_content, line);
		free(file_content);
		file_content = temp;
		free(line);
		line = get_next_line(game->map->fd);
	}
	close(game->map->fd);
	game->map->parsed_file = ft_split_special(file_content);
}

void	parser(t_game *game)
{
	parse_file(game);
}
