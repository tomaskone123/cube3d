/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:08:57 by tomas             #+#    #+#             */
/*   Updated: 2025/09/26 15:24:56 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
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
		if (!is_empty_line(line))
		{
			temp = ft_strjoin(file_content, line);
			free(file_content);
			file_content = temp;
		}
		free(line);
		line = get_next_line(game->map->fd);
	}
	close(game->map->fd);
	game->map->parsed_file = ft_split(file_content, '\n');
	free(file_content);
}

void	parser(t_game *game)
{
	parse_file(game);
	check_duplicates(game);
	get_textures_and_colors(game);
	get_map(game);
}
