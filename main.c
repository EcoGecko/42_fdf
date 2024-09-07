/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:26:32 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:13:05 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "control_keys.h"
#include "control_mouse.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.mlx = NULL;
	fdf.win = NULL;
	fdf.img.img = NULL;
	fdf.map.points = NULL;
	fdf.map.str_map = NULL;
	if (argc != 2)
		terminate(&fdf, ERROR_ARGS, 1, 0);
	fdf.file = argv[1];
	init_keys(&fdf);
	map_init(&fdf, &fdf.map);
	initializer(&fdf, 0);
	render(&fdf);
	mlx_hook(fdf.win, ButtonPress, ButtonPressMask, button_press, &fdf);
	mlx_hook(fdf.win, ButtonRelease, ButtonReleaseMask, button_release, &fdf);
	mlx_hook(fdf.win, KeyPress, KeyPressMask, key_press, &fdf);
	mlx_hook(fdf.win, KeyRelease, KeyReleaseMask, key_release, &fdf);
	mlx_hook(fdf.win, MotionNotify, ButtonMotionMask, mouse_pos, &fdf);
	mlx_hook(fdf.win, DestroyNotify, NoEventMask, exit_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
