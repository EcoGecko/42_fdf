/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:36:24 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:22:09 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*map initializer*/
void	map_init(t_fdf *fdf, t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->size = 0;
	map->scale = 1;
	map->z_depth = 1;
	map->z_factor = 1;
	map->str_map = ft_calloc(1, 1);
	map->points = NULL;
	map->projected = NULL;
	get_map_size(map, fdf);
	get_points(fdf);
	z_scale(&fdf->map);
}

/*Function to get map size, width and height and validate line size*/
void	get_map_size(t_map *map, t_fdf *fdf)
{
	int		i;
	int		points;

	extract_map(map, fdf);
	i = -1;
	points = 0;
	while (map->str_map[++i])
	{
		if (ft_isalnum(map->str_map[i]) && (map->str_map[i + 1] == ' ' || \
		map->str_map[i + 1] == '\n' || map->str_map[i + 1] == '\0'))
			points++;
		if (map->str_map[i] == '\n' || !map->str_map[i + 1])
		{
			if (map->str_map[i + 1])
				map->height++;
			if (map->width != 0 && (map->width != points))
				terminate(fdf, ERROR_LINE, 1, 0);
			else
				map->width = points;
			points = 0;
		}
	}
	if (points > 0 && (map->width != points))
		terminate(fdf, ERROR_LINE, 1, 0);
	map->size = ++map->height * map->width;
}

/*Loads the points from the string to the map struct*/
void	load_points(char *set, t_map *map, int y, t_fdf *fdf)
{
	char	**splitted;
	int		color;
	int		i;

	splitted = ft_split(set, ' ');
	map->scale = .9f * fminf(WIN_WIDTH, WIN_HEIGHT) / \
	(float)sqrt(pow(map->height, 2) + \
			pow(map->width, 2));
	i = 0;
	while (splitted[i] && splitted[i][0] != '\n')
	{
		validate_content(&splitted[i][0], fdf);
		map->points[fdf->point].coord[0] = (i - map->width / 2) * map->scale;
		map->points[fdf->point].coord[1] = (y - map->height / 2) * map->scale;
		map->points[fdf->point].coord[2] = ft_atoi(&splitted[i][0]);
		color = get_point_color(&splitted[i][0]);
		if (color == -1)
			map->points[fdf->point].map_color = WHITE;
		else
			map->points[fdf->point].map_color = color;
		i++;
		fdf->point++;
	}
	ft_db_free(splitted);
}

/*function to get points | get them from split string and store it
in a struct*/
void	get_points(t_fdf *fdf)
{
	int		i;
	int		y;
	char	*set;
	char	*prev_set;

	fdf->map.points = ft_calloc(fdf->map.size, sizeof(t_point));
	fdf->point = 0;
	prev_set = fdf->map.str_map;
	set = NULL;
	y = 0;
	i = 0;
	while (++i)
	{
		if (fdf->map.str_map[i] == '\n' || !fdf->map.str_map[i])
		{
			free(set);
			set = ft_substr(prev_set, 0, &fdf->map.str_map[i] - prev_set);
			prev_set = &fdf->map.str_map[i + 1];
			load_points(set, &fdf->map, y++, fdf);
			if (!fdf->map.str_map[i])
				break ;
		}
	}
	free(set);
}
