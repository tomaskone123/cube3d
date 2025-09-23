/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:28:37 by tomas             #+#    #+#             */
/*   Updated: 2025/09/23 14:23:00 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	file_exists(char *filepath, char* extention, t_game *game)
{
	int result;
	int len;
	int len_extention;

	result = 0;
	len = ft_strlen(filepath);
	result = open(filepath, O_RDONLY);
	if (result <= 0)
		error_exit(FAIL_OPEN_FILE, game);
	close(result);
	if (extention)
	{
		len_extention = ft_strlen(extention);
		if (ft_strncmp(&filepath[len - len_extention ], extention, len_extention) == 0)
			return (0);
		if (ft_strncmp(CUB, extention, ft_strlen(extention)) == 0)
			error_exit(EXTENTION_CUB_FAIL, game);
		else
			error_exit(EXTENTION_PNG_FAIL, game);
	}
	return (0);
}


int	is_space(char value)
{
	if ((7 <= value && value <= 13) || value == 32)
		return (1);
	else
		return (0);
}

int	space_increment(char* string, int number)
{
	while (string[number])
	{
		if (is_space(string[number]))
			number++;
		else
			break;
	}
	return (number);
}

