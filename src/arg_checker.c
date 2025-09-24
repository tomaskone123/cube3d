/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:41:01 by tomas             #+#    #+#             */
/*   Updated: 2025/09/24 13:18:43 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	argument_check(char *map_argument, int argc, t_game *game)
{
	if (argc != 2)
		error_exit(ARGUMENT_NUMBER_FAIL, game);
	file_exists(map_argument, CUB, game);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		error_exit(MALOC_FAIL_MAP, game);
	game->map->fd = open(map_argument, O_RDONLY);
	return (0);
}
