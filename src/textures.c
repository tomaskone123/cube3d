/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:57:40 by tomas             #+#    #+#             */
/*   Updated: 2025/09/24 12:08:29 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static void parse_texture_line(char *line, t_game* game)
{
	int	i;

	i = 0;
	t_txt_array txt[] = {
		{"NO", &game->map->no_texture},
		{"SO", &game->map->so_texture},
		{"WE", &game->map->we_texture},
		{"EA", &game->map->ea_texture},
		{NULL, NULL}
	};
	while (txt[i].id)
	{
		if (ft_strncmp(line, txt[i].id, 2) == 0)
		{
			line +=2;
			while (*line && is_space(*line))
				line++;
			*(txt[i].texture) = ft_strtrim(line, " \t\n\r\v\f");
			if (!*(txt[i].texture))
				error_exit(MALOC_FAIL_TEXTURE, game);
			break;
		}
		i++;
	}
}

static void	parse_colour_line(char* line, t_game* game)
{
	// ft_printf("%s\n", line);
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		line++;
		while (*line && is_space(*line))
			line++;
		game->map->ceiling_color = ft_strtrim(line, " \t\n\r\v\f");
		if (!game->map->ceiling_color)
			error_exit(MALOC_FAIL_COLOUR, game);
		// ft_printf("C:%s\n", game->map->ceiling_color);
	}
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		line++;
		while (*line && is_space(*line))
			line++;
		game->map->floor_color = ft_strtrim(line, " \t\n\r\v\f");
		if (!game->map->floor_color)
			error_exit(MALOC_FAIL_COLOUR, game);
		// ft_printf("F:%s\n", game->map->floor_color);
	}
}

int	get_textures(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (game->map->parsed_file[i])
	{
		line = game->map->parsed_file[i];
		while (is_space(*line))
			line++;
		parse_texture_line(line, game);
		parse_colour_line(line, game);
		i++;
	}
	// ft_printf("NO:%s\nSO:%s\nWE:%s\nEA:%s\nC:%s\nF:%s\n", game->map->no_texture, game->map->so_texture, game->map->we_texture, game->map->ea_texture, game->map->ceiling_color, game->map->floor_color);
	return (0);
}
