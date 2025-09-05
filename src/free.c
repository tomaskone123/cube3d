/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:43:08 by tomas             #+#    #+#             */
/*   Updated: 2025/09/05 13:43:52 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int free_game(t_game *game)
{
	// HAVE TO ADD FREEING OF MAP LATER WHEN I ADD THE MAP VARIABLES
	if (game->map)
		free(game->map);
	if (game)
		free(game);
	return (0);
}
