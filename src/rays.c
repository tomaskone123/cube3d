// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   rays.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/10/08 14:45:54 by tomas             #+#    #+#             */
// /*   Updated: 2025/10/21 14:22:04 by tomas            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../inc/cube3d.h"

// // void	cast_ray(t_game *game, float ray_angle)
// // {
// // 	float	ray_x;
// // 	float	ray_y;
// // 	float	step;
// // 	int		mapx;
// // 	int		mapy;
// // 	bool	hit;

// // 	hit = false;
// // 	step = 0.05f;
// // 	ray_x = game->player->px;
// // 	ray_y = game->player->py;
// // 	while (!hit)
// // 	{
// // 		ray_x += cos(ray_angle) * step;
// // 		ray_y += sin(ray_angle) * step;
// // 		mapx = (int)ray_x;
// // 		mapy = (int)ray_y;
// // 		if (game->map->map_grid[mapy][mapx] == '1')
// // 			hit = true;
// // 		mapx = (int)(ray_x * TILE);
// // 		mapy = (int)(ray_y * TILE);
// // 		if (mapx >= 0 && mapx < WIDTH && mapy >= 0 && mapy < HEIGHT)
// // 			mlx_put_pixel(game->frame, mapx, mapy, 0x00FF00FF);
// // 	}
// // }

// char	get_wall_dir(t_ray *ray, float ray_angle)
// {
// 	float	dist_to_vert;
// 	float	dist_to_horizont;

// 	dist_to_vert = fabsf(ray->x - floorf(ray->x));
// 	dist_to_horizont = fabsf(ray->y - floorf(ray->y));
// 	if (dist_to_vert < dist_to_horizont)
// 	{
// 		if (cos(ray_angle) > 0)
// 			return ('E');
// 		else
// 			return ('W');
// 	}
// 	else
// 	{
// 		if (sin(ray_angle) > 0)
// 			return ('S');
// 		else
// 			return ('N');
// 	}
// 	return ('S');
// }

// uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
// {
// 	int		index;
// 	uint8_t	*p;

// 	index = (y * texture->width + x) * 4;
// 	p = &texture->pixels[index];
// 	return (p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
// }

// void	cast_ray(t_game *game, float ray_angle, int column)
// {
// 	mlx_texture_t	*texture;
// 	int				mapx;
// 	int				mapy;
// 	float			wall_height;
// 	float			step;
// 	float			tex_pos;
// 	int				tex_y;
// 	uint32_t		color;

// 	// int				j;
// 	// j = 0;
// 	game->ray->hit = false;
// 	// game->ray->step = 1.0f / TILE;
// 	game->ray->step = PIXELATION;
// 	game->ray->x = game->player->px;
// 	game->ray->y = game->player->py;
// 	while (!game->ray->hit)
// 	{
// 		game->ray->x += cos(ray_angle) * game->ray->step;
// 		game->ray->y += sin(ray_angle) * game->ray->step;
// 		mapx = (int)game->ray->x;
// 		mapy = (int)game->ray->y;
// 		if (game->map->map_grid[mapy][mapx] == '1')
// 		{
// 			game->ray->hit = true;
// 			game->ray->wall_dir = get_wall_dir(game->ray, ray_angle);
// 		}
// 	}
// 	get_start_end(game, ray_angle);
// 	texture = get_texture(game);
// 	if (game->ray->wall_dir == 'E' || game->ray->wall_dir == 'W')
// 		game->ray->wall_x = game->ray->y - floorf(game->ray->y);
// 	else
// 		game->ray->wall_x = game->ray->x - floorf(game->ray->x);
// 	game->ray->tex_x = (int)(game->ray->wall_x * texture->width);
// 	wall_height = game->ray->end - game->ray->start;
// 	step = (float)texture->height / wall_height;
// 	tex_pos = 0.0f;
// 	// 4️⃣ Draw textured wall slice
// 	for (int j = game->ray->start; j < game->ray->end; j++)
// 	{
// 		tex_y = (int)tex_pos;
// 		color = get_texture_color(texture, game->ray->tex_x, tex_y);
// 		mlx_put_pixel(game->frame, column, j, color);
// 		tex_pos += step;
// 	}
// 	// j = game->ray->start;
// 	// while (j < game->ray->end)
// 	// 	mlx_put_pixel(game->frame, column, j++, 0xFFFFFF);
// }

// void	cast_all_rays(t_game *game)
// {
// 	int		num_rays;
// 	float	fov;
// 	float	start_angle;
// 	float	angle_step;
// 	int		i;

// 	num_rays = WIDTH;
// 	fov = M_PI / 3;
// 	start_angle = game->player->angle - fov / 2;
// 	angle_step = fov / num_rays;
// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		cast_ray(game, start_angle + i * angle_step, i);
// 		i++;
// 	}
// }

#include "../inc/cube3d.h"

/* -------------------------------------------------------------------------- */
/* INIT DDA */
/* -------------------------------------------------------------------------- */
void init_dda(t_game *game, float ray_angle, t_dda *dda)
{
    dda->ray_dir_x = cos(ray_angle);
    dda->ray_dir_y = sin(ray_angle);

    dda->map_x = (int)game->player->px;
    dda->map_y = (int)game->player->py;

    dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
    dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
}

/* -------------------------------------------------------------------------- */
/* CALCULATE STEP AND SIDE DIST */
/* -------------------------------------------------------------------------- */
void calc_step_and_side_dist(t_game *game, t_dda *dda)
{
    if (dda->ray_dir_x < 0)
    {
        dda->step_x = -1;
        dda->side_dist_x = (game->player->px - dda->map_x) * dda->delta_dist_x;
    }
    else
    {
        dda->step_x = 1;
        dda->side_dist_x = (dda->map_x + 1.0 - game->player->px) * dda->delta_dist_x;
    }

    if (dda->ray_dir_y < 0)
    {
        dda->step_y = -1;
        dda->side_dist_y = (game->player->py - dda->map_y) * dda->delta_dist_y;
    }
    else
    {
        dda->step_y = 1;
        dda->side_dist_y = (dda->map_y + 1.0 - game->player->py) * dda->delta_dist_y;
    }
}

/* -------------------------------------------------------------------------- */
/* PERFORM DDA - FIND WALL HIT */
/* -------------------------------------------------------------------------- */
void perform_dda(t_game *game, t_dda *dda)
{
    game->ray->hit = false;

    while (!game->ray->hit)
    {
        if (dda->side_dist_x < dda->side_dist_y)
        {
            dda->side_dist_x += dda->delta_dist_x;
            dda->map_x += dda->step_x;
            game->ray->hit_vertical = true;
        }
        else
        {
            dda->side_dist_y += dda->delta_dist_y;
            dda->map_y += dda->step_y;
            game->ray->hit_vertical = false;
        }

        if (game->map->map_grid[dda->map_y][dda->map_x] == '1')
            game->ray->hit = true;
    }
}

/* -------------------------------------------------------------------------- */
/* CALCULATE PERPENDICULAR DISTANCE */
/* -------------------------------------------------------------------------- */
float calc_perp_distance(t_game *game, t_dda *dda)
{
    float perp_dist;

    if (game->ray->hit_vertical)
        perp_dist = (dda->map_x - game->player->px + (1 - dda->step_x) / 2) / dda->ray_dir_x;
    else
        perp_dist = (dda->map_y - game->player->py + (1 - dda->step_y) / 2) / dda->ray_dir_y;

    return (perp_dist);
}

/* -------------------------------------------------------------------------- */
/* CALCULATE WALL DRAW BOUNDS */
/* -------------------------------------------------------------------------- */
void calc_wall_bounds(t_game *game, float perp_dist)
{
    int wall_height;

    wall_height = (int)(HEIGHT / perp_dist);

    game->ray->start = -wall_height / 2 + HEIGHT / 2;
    if (game->ray->start < 0)
        game->ray->start = 0;

    game->ray->end = wall_height / 2 + HEIGHT / 2;
    if (game->ray->end >= HEIGHT)
        game->ray->end = HEIGHT - 1;
}

/* -------------------------------------------------------------------------- */
/* DETERMINE WALL DIRECTION */
/* -------------------------------------------------------------------------- */
void set_wall_direction(t_game *game, t_dda *dda)
{
    if (game->ray->hit_vertical)
        game->ray->wall_dir = (dda->ray_dir_x > 0) ? 'E' : 'W';
    else
        game->ray->wall_dir = (dda->ray_dir_y > 0) ? 'S' : 'N';
}

/* -------------------------------------------------------------------------- */
/* CALCULATE TEXTURE X COORDINATE */
/* -------------------------------------------------------------------------- */
void calc_texture_x(t_game *game, t_dda *dda, float perp_dist, mlx_texture_t *texture)
{
    if (game->ray->hit_vertical)
        game->ray->wall_x = game->player->py + perp_dist * dda->ray_dir_y;
    else
        game->ray->wall_x = game->player->px + perp_dist * dda->ray_dir_x;

    game->ray->wall_x -= floor(game->ray->wall_x);
    game->ray->tex_x = (int)(game->ray->wall_x * texture->width);

    // Flip texture if needed for correct orientation
    if ((!game->ray->hit_vertical && dda->ray_dir_x > 0) ||
        (game->ray->hit_vertical && dda->ray_dir_y < 0))
        game->ray->tex_x = texture->width - game->ray->tex_x - 1;
}


/* -------------------------------------------------------------------------- */
/* TEXTURE SAMPLING */
/* -------------------------------------------------------------------------- */
uint32_t get_texture_color(mlx_texture_t *texture, int x, int y)
{
    int index;
    uint8_t *p;

    if (x < 0)
        x = 0;
    if (x >= (int)texture->width)
        x = texture->width - 1;
    if (y < 0)
        y = 0;
    if (y >= (int)texture->height)
        y = texture->height - 1;

    index = (y * texture->width + x) * 4;
    p = &texture->pixels[index];
    return (p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
}

/* -------------------------------------------------------------------------- */
/* DRAW TEXTURED WALL COLUMN */
/* -------------------------------------------------------------------------- */
void draw_wall_column(t_game *game, mlx_texture_t *texture, int column, float perp_dist)
{
    float step;
    float tex_pos;
    int tex_y;
    uint32_t color;
    int wall_height;

    wall_height = (int)(HEIGHT / perp_dist);
    step = (float)texture->height / wall_height;
    tex_pos = (game->ray->start - HEIGHT / 2 + wall_height / 2) * step;

    for (int j = game->ray->start; j < game->ray->end; j++)
    {
        tex_y = (int)tex_pos & (texture->height - 1);
        tex_pos += step;
        color = get_texture_color(texture, game->ray->tex_x, tex_y);
        mlx_put_pixel(game->frame, column, j, color);
    }
}


/* -------------------------------------------------------------------------- */
/* MAIN CAST RAY FUNCTION */
/* -------------------------------------------------------------------------- */
void cast_ray(t_game *game, float ray_angle, int column)
{
    t_dda dda;
    float perp_dist;
    mlx_texture_t *texture;

    // 1. Initialize DDA variables
    init_dda(game, ray_angle, &dda);

    // 2. Calculate step direction and initial side distances
    calc_step_and_side_dist(game, &dda);

    // 3. Perform DDA to find wall hit
    perform_dda(game, &dda);

    // 4. Calculate perpendicular distance (fixes fisheye)
    perp_dist = calc_perp_distance(game, &dda);

    // 5. Calculate wall drawing bounds
    calc_wall_bounds(game, perp_dist);

    // 6. Determine which wall was hit
    set_wall_direction(game, &dda);

    // 7. Get appropriate texture
    texture = get_texture(game);

    // 8. Calculate texture X coordinate
    calc_texture_x(game, &dda, perp_dist, texture);

    // 9. Draw the textured wall column
    draw_wall_column(game, texture, column, perp_dist);
}

/* -------------------------------------------------------------------------- */
/* CAST ALL RAYS */
/* -------------------------------------------------------------------------- */
void cast_all_rays(t_game *game)
{
    int num_rays;
    float fov;
    float start_angle;
    float angle_step;
    int i;

    num_rays = WIDTH;
    fov = M_PI / 3;
    start_angle = game->player->angle - fov / 2;
    angle_step = fov / num_rays;

    i = 0;
    while (i < WIDTH)
    {
        cast_ray(game, start_angle + i * angle_step, i);
        i++;
    }
}
