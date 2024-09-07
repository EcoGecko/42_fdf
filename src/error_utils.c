/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:30 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:18:06 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->shift[0] = 0;
	fdf->shift[1] = 0;
	fdf->zoom = 1;
	fdf->map.z_depth = 1;
	fdf->projection = 0;
	fdf->mode = 0;
	fdf->colorscheme = 0;
	fdf->inverter = 1;
	fdf->map.angle[0] = 30;
	fdf->map.angle[1] = -30;
	fdf->map.angle[2] = 30;
	fdf->mode_name = "Wired";
	fdf->color_name = "Original";
	fdf->proj_name = "Isometric";
}

void	initializer(t_fdf *fdf, int reset)
{
	if (!reset)
	{
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, \
				"heda-sil-FDF");
		fdf->img.img = mlx_new_image(fdf->mlx, WIN_WIDTH, \
				WIN_HEIGHT);
		fdf->img.addr = mlx_get_data_addr(fdf->img.img, \
				&fdf->img.bits_per_pixel, &fdf->img.line_length, \
				&fdf->img.endian);
	}
	fdf_init(fdf);
}

/*terminates the program and shows the necessary error message*/
void	terminate(t_fdf *prog, char *str, int exit_status, int system)
{
	if (!system)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	terminate_prog(prog, exit_status);
}

/*Handle closing window by clicking the close button*/
int	exit_hook(void *param)
{
	terminate_prog(param, 0);
	return (0);
}

/*Terminates the program*/
void	terminate_prog(t_fdf *prog, int exit_status)
{
	if (prog->img.img)
		mlx_destroy_image(prog->mlx, prog->img.img);
	if (prog->win)
		mlx_destroy_window(prog->mlx, prog->win);
	if (prog->mlx)
	{
		mlx_destroy_display(prog->mlx);
		free(prog->mlx);
	}
	free(prog->map.points);
	free(prog->map.str_map);
	exit(exit_status);
}
