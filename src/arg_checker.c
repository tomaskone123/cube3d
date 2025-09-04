/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:41:01 by tomas             #+#    #+#             */
/*   Updated: 2025/09/04 15:47:58 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	argument_check(char *argv[], int argc, t_game *game)
{
	int		len;

	if (argc != 2)
		error_exit(ARGUMENT_NUMBER_FAIL, game);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
		error_exit(ARGUMENT_TYPE_FAIL, game);

		// add the map init here where the functions check the file if it's openable and get all the neccessary data from the .cub file

	return (0);
}
