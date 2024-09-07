/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:20:01 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:16:33 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control_mouse.h"

/*Handles mouse button press and scroll wheel*/
int	button_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == 1)
	{
		fdf->key.mouse_l = 1;
		fdf->mouse[0] = x;
		fdf->mouse[1] = y;
	}
	if (button == 3)
	{
		fdf->key.mouse_r = 1;
		fdf->mouse[0] = x;
		fdf->mouse[1] = y;
	}
	if (button == 4)
		fdf->zoom *= ZOOM;
	if (button == 5)
		fdf->zoom /= ZOOM;
	render(fdf);
	return (0);
}

/*Handles mouse button release*/
int	button_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)x;
	(void)y;
	if (button == 1)
		fdf->key.mouse_l = 0;
	if (button == 3)
		fdf->key.mouse_r = 0;
	return (0);
}

/*Handles mouse movement*/
int	mouse_pos(int x, int y, void *param)
{
	t_fdf	*fdf;
	int		dx;
	int		dy;

	fdf = (t_fdf *)param;
	dx = fdf->mouse[0] - x;
	dy = fdf->mouse[1] - y;
	if (fdf->key.mouse_r)
	{
		fdf->map.angle[0] += dy;
		fdf->map.angle[1] -= dx;
		fdf->map.angle[2] += ((dx + dy) / 2);
		fdf->mouse[0] = x;
		fdf->mouse[1] = y;
	}
	if (fdf->key.mouse_l)
	{
		fdf->shift[0] -= dx;
		fdf->shift[1] -= dy;
		fdf->mouse[0] = x;
		fdf->mouse[1] = y;
	}
	render(fdf);
	return (0);
}
