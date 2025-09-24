/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:12:49 by tomas             #+#    #+#             */
/*   Updated: 2025/09/24 19:57:51 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static int	split_clrs(char *color, t_game *game)
{
	char	**clr_array;
	int		r;
	int		g;
	int		b;

	clr_array = ft_split(color, ',');
	if (array_size(clr_array) != 3)
	{
		free_array(clr_array);
		error_exit(CLR_NOT_ENOUGH, game);
	}
	r = ft_atoi(clr_array[0]);
	g = ft_atoi(clr_array[1]);
	b = ft_atoi(clr_array[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_array(clr_array);
		error_exit(CLR_NOT_ENOUGH, game);
	}
	free_array(clr_array);
	return ((uint32_t)((0xFF << 24) | (r << 16) | (g << 8) | b));
}

int	color_convert(char *color, t_game *game)
{
	int			i;
	uint32_t	result;

	i = 0;
	while (color[i])
	{
		if (color[i] == ',')
			i++;
		if (ft_isdigit(color[i]) == 1)
			i++;
		else
			error_exit(CLR_WRONG_NUMBER, game);
	}
	result = split_clrs(color, game);
	return (result);
}
