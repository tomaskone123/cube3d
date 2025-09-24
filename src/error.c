/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:33:58 by tomas             #+#    #+#             */
/*   Updated: 2025/09/24 13:15:45 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	error_exit(char *error_message, t_game *game)
{
	ft_printf("Error\n");
	ft_printf(error_message);
	ft_printf("\n");
	if (game)
		free_game(game);
	exit(1);
}
