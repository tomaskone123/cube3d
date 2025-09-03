/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:31:50 by tomas             #+#    #+#             */
/*   Updated: 2025/09/03 15:54:12 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int32_t main(int argc, char* argv[])
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_exit(MALOC_FAIL_GAME, game);
	if (argc == 1)
		ft_printf(argv[0]);
	return (EXIT_SUCCESS);
}
