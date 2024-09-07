/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:14:13 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:24:23 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	z_scale(t_map *map)
{
	int	i;

	i = 0;
	map->z_max = 0;
	map->z_min = 0;
	while (i < map->size)
	{
		if (map->points[i].coord[2] > map->z_max)
			map->z_max = map->points[i].coord[2];
		if (map->points[i].coord[2] < map->z_min)
			map->z_min = map->points[i].coord[2];
		i++;
	}
	if (map->z_max != map->z_min)
		map->z_factor = .09f * ((float)(fmax(map->height, map->width) * \
		map->scale) / fabsf(map->z_max - map->z_min));
	i = -1;
	while (++i < map->size)
		map->points[i].coord[2] *= map->z_factor;
}

void	z_factoring(t_map *map)
{
	int	i;

	if (map->z_depth > 7.5f)
		map->z_depth = 7.5f;
	if (map->z_depth < .05f)
		map->z_depth = 0.05f;
	i = -1;
	while (++i < map->size)
		map->projected[i].coord[2] *= map->z_depth;
}

/*will be replaced with scale function*/
void	fit_map(t_point *fitted, t_fdf *fdf)
{
	int	size;

	size = fdf->map.size;
	if (fdf->zoom > 56)
		fdf->zoom /= ZOOM;
	if (fdf->zoom < 0.5f)
	{
		fdf->zoom *= ZOOM;
	}
	while (--size >= 0)
	{
		fitted[size].coord[0] = roundf((fitted[size].coord[0] * fdf->zoom + \
		(float)fdf->shift[0]) + (float)WIN_WIDTH / 2);
		fitted[size].coord[1] = roundf((fitted[size].coord[1] * fdf->zoom + \
		(float)fdf->shift[1]) + (float)WIN_HEIGHT / 2);
	}
}

/*Parses the map points according to projection, scale and position*/
void	parse_map(t_map *map, t_fdf *fdf)
{
	map->projected = ft_calloc(map->size, sizeof(t_point));
	copy_map(map->points, map->projected, map->size);
	z_factoring(map);
	x_rotation(map->projected, map->angle[0], map->size);
	y_rotation(map->projected, map->angle[1], map->size);
	z_rotation(map->projected, map->angle[2], map->size);
	ortho_project(map->projected, map->size);
	map->fitted = ft_calloc(map->size, sizeof(t_point));
	copy_map(map->projected, map->fitted, map->size);
	free(fdf->map.projected);
	fit_map(map->fitted, fdf);
}
