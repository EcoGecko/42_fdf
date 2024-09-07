/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:12:13 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:16:07 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control_keys.h"

/*Handle keyboard presses*/
int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	set_keys(key, fdf, 1);
	if (key == XK_Escape)
		terminate_prog(fdf, 0);
	if (key == XK_m)
		fdf->mode++;
	if (key == XK_p)
		set_projection(fdf);
	if (key == XK_c)
		fdf->colorscheme++;
	if (key == XK_Home)
	{
		fdf->shift[0] = 0;
		fdf->shift[1] = 0;
	}
	if (key == XK_h)
		fdf->key.help *= -1;
	if (key == XK_r)
		initializer(fdf, 1);
	render(fdf);
	return (0);
}

/*Handle keyboard releases*/
int	key_release(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	set_keys(key, fdf, 0);
	return (0);
}

/*apply key effect*/
void	apply_keys(t_fdf *fdf)
{
	if ((float)fdf->map.width * fdf->map.scale * fdf->zoom > WIN_WIDTH && \
	(float)fdf->map.height * fdf->map.scale * fdf->zoom > WIN_HEIGHT)
		fdf->inverter = -1;
	else
		fdf->inverter = 1;
	if (fdf->key.plus)
		fdf->zoom *= ZOOM;
	if (fdf->key.minus)
		fdf->zoom /= ZOOM;
	if (fdf->key.up && !fdf->key.down)
		fdf->shift[1] -= (int)ceilf(SHIFT * fdf->zoom) * fdf->inverter;
	if (fdf->key.down && !fdf->key.up)
		fdf->shift[1] += (int)ceilf(SHIFT * fdf->zoom) * fdf->inverter;
	if (fdf->key.left && !fdf->key.right)
		fdf->shift[0] -= (int)ceilf(SHIFT * fdf->zoom) * fdf->inverter;
	if (fdf->key.right && !fdf->key.left)
		fdf->shift[0] += (int)ceilf(SHIFT * fdf->zoom) * fdf->inverter;
	if (fdf->key.comma)
		fdf->map.z_depth /= ZOOM;
	if (fdf->key.period)
		fdf->map.z_depth *= ZOOM;
}

/*Sets key on or off*/
void	set_keys(int key, t_fdf *fdf, int value)
{
	if (key == XK_KP_Add || key == XK_equal)
		fdf->key.plus = value;
	if (key == XK_KP_Subtract || key == XK_minus)
		fdf->key.minus = value;
	if (key == XK_Up || key == XK_w)
		fdf->key.up = value;
	if (key == XK_Down || key == XK_s)
		fdf->key.down = value;
	if (key == XK_Left || key == XK_a)
		fdf->key.left = value;
	if (key == XK_Right || key == XK_d)
		fdf->key.right = value;
	if (key == XK_comma)
		fdf->key.comma = value;
	if (key == XK_period)
		fdf->key.period = value;
}

/*Init key struct*/
void	init_keys(t_fdf *fdf)
{
		fdf->key.up = 0;
		fdf->key.down = 0;
		fdf->key.left = 0;
		fdf->key.right = 0;
		fdf->key.plus = 0;
		fdf->key.minus = 0;
		fdf->key.comma = 0;
		fdf->key.period = 0;
		fdf->key.mouse_l = 0;
		fdf->key.mouse_r = 0;
		fdf->key.help = 1;
}
