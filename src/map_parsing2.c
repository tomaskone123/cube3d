/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuik <skuik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:29:04 by skuik             #+#    #+#             */
/*   Updated: 2026/01/16 15:59:28 by skuik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	is_valid_position(t_game *game, int y, int x, char **visited)
{
	if (y < 0 || y >= game->map->height || x < 0
		|| x >= (int)ft_strlen(visited[y]))
		return (0);
	if (visited[y][x] == ' ')
		return (0);
	return (1);
}

void	push_point(t_flood_stack *fs, t_point p)
{
	t_point	*new_stack;
	int		i;

	if (fs->top >= fs->capacity)
	{
		fs->capacity *= 2;
		new_stack = malloc(sizeof(t_point) * (fs->capacity));
		if (!new_stack)
			return ;
		i = 0;
		while (i < fs->top)
		{
			new_stack[i] = fs->stack[i];
			i++;
		}
		free(fs->stack);
		fs->stack = new_stack;
	}
	fs->stack[fs->top++] = p;
}

int	fill_neighbors(t_game *game, t_point current,
		t_flood_stack *fs, char **visited)
{
	if (!is_valid_position(game, current.y, current.x, visited))
		return (0);
	if (visited[current.y][current.x] == '1'
		|| visited[current.y][current.x] == 'V')
		return (1);
	visited[current.y][current.x] = 'V';
	push_point(fs, (t_point){current.y - 1, current.x});
	push_point(fs, (t_point){current.y + 1, current.x});
	push_point(fs, (t_point){current.y, current.x - 1});
	push_point(fs, (t_point){current.y, current.x + 1});
	return (1);
}

int	flood_fill(t_game *game, int y, int x, char **visited)
{
	t_flood_stack	fs;
	t_point			current;

	fs.capacity = 1024;
	fs.stack = malloc(sizeof(t_point) * fs.capacity);
	if (!fs.stack)
		return (0);
	fs.top = 0;
	push_point(&fs, (t_point){y, x});
	while (fs.top > 0)
	{
		current = fs.stack[--fs.top];
		if (!fill_neighbors(game, current, &fs, visited))
		{
			free(fs.stack);
			return (0);
		}
	}
	free(fs.stack);
	return (1);
}
