/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:34:12 by tomas             #+#    #+#             */
/*   Updated: 2025/09/03 15:47:10 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# define MALOC_FAIL_GAME "Couldn't allocate memory for the 'game' struct\n"

typedef struct	s_game
{
	mlx_t		*mlx;

}				t_game;

void error_exit(char *error_message, t_game *game);
int free_game(t_game *game);

#endif
