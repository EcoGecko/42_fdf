/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:29:46 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:24:10 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*Rendering function, will use to put all the drawings to the screen*/
int	render(t_fdf *fdf)
{
	if (!fdf->win)
		terminate(fdf, "Window error", 1, 1);
	if (!handle_image(fdf))
		terminate(fdf, "Image error", 1, 1);
	apply_keys(fdf);
	set_colorscheme(fdf);
	parse_map(&fdf->map, fdf);
	set_mode(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, \
	fdf->img.img, 0, 0);
	if (fdf->key.help > 0)
		render_menu(fdf);
	free(fdf->map.fitted);
	return (0);
}

void	set_mode(t_fdf *fdf)
{
	if (fdf->mode > 2)
		fdf->mode = 0;
	if (fdf->mode == 0)
	{
		fdf->mode_name = "Wired";
		wired(fdf, fdf->map.fitted);
	}
	if (fdf->mode == 1)
	{
		fdf->mode_name = "Both";
		wired(fdf, fdf->map.fitted);
		doted(fdf, fdf->map.fitted);
	}
	if (fdf->mode == 2)
	{
		fdf->mode_name = "Doted";
		doted(fdf, fdf->map.fitted);
	}
}

void	set_projection(t_fdf *fdf)
{
	fdf->projection++;
	if (fdf->projection == 3)
		fdf->projection = 0;
	if (fdf->projection == 0)
	{
		fdf->proj_name = "Isometric";
		fdf->map.angle[0] = 30;
		fdf->map.angle[1] = -30;
		fdf->map.angle[2] = 30;
	}
	else if (fdf->projection == 2)
	{
		fdf->proj_name = "Top view";
		fdf->map.angle[0] = 0;
		fdf->map.angle[1] = 0;
		fdf->map.angle[2] = 0;
	}
	else if (fdf->projection == 1)
	{
		fdf->proj_name = "Front view";
		fdf->map.angle[0] = 90;
		fdf->map.angle[1] = 0;
		fdf->map.angle[2] = 0;
	}
}

void	set_colorscheme(t_fdf *fdf)
{
	if (fdf->colorscheme == 3)
		fdf->colorscheme = 0;
	if (fdf->colorscheme == 2)
	{
		fdf->color_name = "Rainbow";
		fdf->map.colorscheme.top_level = VIOLET;
		fdf->map.colorscheme.high_level = INDIGO;
		fdf->map.colorscheme.medium_level = BLUE;
		fdf->map.colorscheme.ground_level = GREEN;
		fdf->map.colorscheme.ground_low = YELLOW;
		fdf->map.colorscheme.sea_level = ORANGE;
		fdf->map.colorscheme.sea_low = RED;
	}
	if (fdf->colorscheme == 1)
	{
		fdf->color_name = "Terrain";
		fdf->map.colorscheme.top_level = WHITE;
		fdf->map.colorscheme.high_level = GRAY;
		fdf->map.colorscheme.medium_level = BROWN;
		fdf->map.colorscheme.ground_level = DARK_GREEN;
		fdf->map.colorscheme.ground_low = SANDY_YELLOW;
		fdf->map.colorscheme.sea_level = BLUE;
		fdf->map.colorscheme.sea_low = NAVY_BLUE;
	}
	set_color(fdf, &fdf->map);
}

void	set_color(t_fdf *fdf, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->size)
	{
		if (map->points[i].coord[2] >= (map->z_max * .7) * map->z_factor)
			map->points[i].color = map->colorscheme.top_level;
		else if (map->points[i].coord[2] >= (map->z_max * .4) * map->z_factor)
			map->points[i].color = map->colorscheme.high_level;
		else if (map->points[i].coord[2] >= (map->z_max * .2) * map->z_factor)
			map->points[i].color = map->colorscheme.medium_level;
		else if (map->points[i].coord[2] > (map->z_max * .05) * map->z_factor)
			map->points[i].color = map->colorscheme.ground_level;
		else if (map->points[i].coord[2] > (map->z_max * .015) * map->z_factor)
			map->points[i].color = map->colorscheme.ground_low;
		else if (map->points[i].coord[2] >= 0.01)
			map->points[i].color = map->colorscheme.sea_low;
		else
			map->points[i].color = map->colorscheme.sea_level;
	}
	if (fdf->colorscheme == 0)
		while (--i >= 0)
			map->points[i].color = map->points[i].map_color;
}
