/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:41:01 by tomas             #+#    #+#             */
/*   Updated: 2025/09/05 13:46:48 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static int map_check(t_game* game, char* map_argument)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		error_exit(MALOC_FAIL_MAP, game);
	game->map->fd = open(map_argument, O_RDONLY); // DO NOR FORGET TO CLOSE THE FILE WHEN DONE READING FROM IT
	if (game->map->fd <= 0)
		error_exit(FAIL_OPEN_FILE, game);
	return (0);
}

int	argument_check(char *argv[], int argc, t_game *game)
{
	int		len;

	if (argc != 2)
		error_exit(ARGUMENT_NUMBER_FAIL, game);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
		error_exit(ARGUMENT_TYPE_FAIL, game);
	map_check(game, argv[1]);
		// add the map init here where the functions check the file if it's openable and get all the neccessary data from the .cub fil
	return (0);
}
