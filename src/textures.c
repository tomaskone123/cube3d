/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:57:40 by tomas             #+#    #+#             */
/*   Updated: 2025/09/25 14:18:12 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static void	load_textures(t_game *game)
{
	game->map->no_mlx_txt = mlx_load_png(game->map->no_texture);
	game->map->so_mlx_txt = mlx_load_png(game->map->so_texture);
	game->map->we_mlx_txt = mlx_load_png(game->map->we_texture);
	game->map->ea_mlx_txt = mlx_load_png(game->map->ea_texture);
	if (!(game->map->no_mlx_txt) || !(game->map->so_mlx_txt)
		|| !(game->map->we_mlx_txt) || !(game->map->ea_mlx_txt))
		error_exit(TXT_LOAD_FAIL, game);
}

static void	init_txt_array(t_game *game, t_txt_array txt[5])
{
	txt[0].id = "NO";
	txt[0].texture = &game->map->no_texture;
	txt[1].id = "SO";
	txt[1].texture = &game->map->so_texture;
	txt[2].id = "WE";
	txt[2].texture = &game->map->we_texture;
	txt[3].id = "EA";
	txt[3].texture = &game->map->ea_texture;
	txt[4].id = NULL;
	txt[4].texture = NULL;
}

static void	parse_texture_line(char *line, t_game *game)
{
	int			i;
	t_txt_array	txt[5];

	init_txt_array(game, txt);
	i = 0;
	while (txt[i].id)
	{
		if (ft_strncmp(line, txt[i].id, 2) == 0)
		{
			line += 2;
			while (*line && is_space(*line))
				line++;
			*(txt[i].texture) = ft_strtrim(line, " \t\n\r\v\f");
			if (!*(txt[i].texture))
				error_exit(MALOC_FAIL_TEXTURE, game);
			break ;
		}
		i++;
	}
}

static void	parse_colour_line(char *line, t_game *game)
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

int	get_textures_and_colors(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (game->map->parsed_file[i] && i <= 6)
	{
		line = game->map->parsed_file[i];
		while (is_space(*line))
			line++;
		parse_texture_line(line, game);
		parse_colour_line(line, game);
		i++;
	}
	// ft_printf("NO:%s\nSO:%s\nWE:%s\nEA:%s\nC:%s\nF:%s\n",
	// 	game->map->no_texture, game->map->so_texture, game->map->we_texture,
	// 	game->map->ea_texture, game->map->ceiling_color,
	// 	game->map->floor_color);
	file_exists(game->map->no_texture, PNG, game);
	file_exists(game->map->so_texture, PNG, game);
	file_exists(game->map->we_texture, PNG, game);
	file_exists(game->map->ea_texture, PNG, game);
	load_textures(game);
	game->map->ceiling_final = color_convert(game->map->ceiling_color, game);
	game->map->floor_final = color_convert(game->map->floor_color, game);
	return (0);
}
