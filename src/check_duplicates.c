/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:06:56 by tomas             #+#    #+#             */
/*   Updated: 2025/09/23 10:56:06 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static void	check_with_value(char* value, t_game* game)
{
	char	**parsed_file;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	parsed_file = game->map->parsed_file;
	while (parsed_file[i])
	{
		j = 0;
		j = space_increment(parsed_file[i], j);
		// ft_printf("spaces:%d | line: %d\n", j, i);
		if (ft_strncmp(parsed_file[i] + j, value, ft_strlen(value)) == 0 && is_space(parsed_file[i][j + ft_strlen(value)]))
			count++;
		i++;
	}
	if (count < 1)
		error_exit(MISSING_VALUE, game);
	if (count > 1)
		error_exit(DUP_VALUE, game);
}

void	check_duplicates(t_game* game)
{
	check_with_value("NO", game);
	check_with_value("SO", game);
	check_with_value("WE", game);
	check_with_value("EA", game);
}
