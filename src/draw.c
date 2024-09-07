/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:05:37 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:22:35 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*Calculates gradient for each drawn pixel*/
int	gradient(int start_color, int end_color, int len, int pos)
{
	double	increment[3];
	int		new[3];
	int		new_color;

	increment[0] = (double)((end_color >> 16) - \
	(start_color >> 16)) / (double)len;
	increment[1] = (double)(((end_color >> 8) & 0xFF) - \
	((start_color >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((end_color & 0xFF) - \
	(start_color & 0xFF)) / (double)len;
	new[0] = (start_color >> 16) + (int)round(pos * increment[0]);
	new[1] = ((start_color >> 8) & 0xFF) + (int)round(pos * increment[1]);
	new[2] = (start_color & 0xFF) + (int)round(pos * increment[2]);
	new_color = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_color);
}

static int	draw(t_point *p0, t_point *p1, t_vars *var)
{
	int	error;

	if (p0->coord[0] == p1->coord[0] && p0->coord[1] == p1->coord[1])
		return (0);
	error = 2 * var->error;
	if (error >= var->dy)
	{
		if (p0->coord[0] == p1->coord[0])
			return (0);
		var->error += var->dy;
		p0->coord[0] += (float)var->sx;
	}
	if (error <= var->dx)
	{
		if (p0->coord[1] == p1->coord[1])
			return (0);
		var->error += var->dx;
		p0->coord[1] += (float)var->sy;
	}
	var->color = gradient(p0->color, p1->color, var->len, \
	var->len - (int)var->dist);
	var->dist--;
	return (1);
}

/*Line drawing function based on bresenham's algorithm*/
void	draw_line(t_point p0, t_point p1, t_img *img)
{
	t_vars	vars;

	vars.sx = -1;
	vars.sy = -1;
	if (((p0.coord[0] < 0 || p0.coord[0] > WIN_WIDTH) && \
	(p0.coord[1] < 0 || p0.coord[1] > WIN_HEIGHT)) && \
	((p1.coord[0] < 0 || p1.coord[0] > WIN_WIDTH) && \
	(p1.coord[1] < 0 || p1.coord[1] > WIN_HEIGHT)))
		return ;
	vars.dx = (int)fabsf(p1.coord[0] - p0.coord[0]);
	if (p0.coord[0] < p1.coord[0])
		vars.sx = 1;
	vars.dy = (int)-fabsf(p1.coord[1] - p0.coord[1]);
	if (p0.coord[1] < p1.coord[1])
		vars.sy = 1;
	vars.error = vars.dx + vars.dy;
	vars.dist = sqrtf(powf(p0.coord[0] - p1.coord[0], 2) + \
	powf(p0.coord[1] - p1.coord[1], 2));
	vars.len = (int)roundf(vars.dist);
	while (draw(&p0, &p1, &vars))
		img_put_pix(img, (int)p0.coord[0], (int)p0.coord[1], vars.color);
}

/*Creates a wire mesh*/
void	wired(t_fdf *fdf, t_point *fitted)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = fdf->map.width;
	height = fdf->map.height;
	while (i < fdf->map.size)
	{
		if (i % width != width - 1 && i / width != height - 1)
		{
			draw_line(fitted[i], fitted[i + 1], &fdf->img);
			draw_line(fitted[i], fitted[i + width], &fdf->img);
		}
		else if (i / width != height - 1)
			draw_line(fitted[i], fitted[i + width], &fdf->img);
		else if (i % width != width - 1)
			draw_line(fitted[i], fitted[i + 1], &fdf->img);
		i++;
	}
}

/*Attempt to draw map points, needs heavy refactoring*/
void	doted(t_fdf *fdf, t_point *fitted)
{
	int	point;
	int	x;
	int	y;
	int	radius;

	radius = (int)roundf(.15f * fdf->map.scale * fdf->zoom);
	if (radius < 1)
		radius = 1;
	point = -1;
	while (++point < fdf->map.size)
	{
		x = -radius;
		while (++x <= radius - 1)
		{
			if ((fitted[point].coord[0] < 0 || \
			fitted[point].coord[0] > WIN_WIDTH) && \
			(fitted[point].coord[1] < 0 || fitted[point].coord[1] > WIN_HEIGHT))
				break ;
			y = -radius - 1;
			while (++y <= radius)
				if ((x * x) + (y * y) <= radius * radius)
					img_put_pix(&fdf->img, (int)fitted[point].coord[0] + x, \
					(int)fitted[point].coord[1] + y, fitted[point].color);
		}
	}
}
