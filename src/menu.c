/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:27:41 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:37:19 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

static void	win_put_nbr(t_fdf *fdf, int tab, int line, float nbr)
{
	char	*str;
	char	*str_int;
	char	*str_dec;
	int		dec;
	char	*tmp;

	if (nbr - (int)nbr)
	{
		dec = (int)((nbr - (int)nbr) * 100);
		str_int = ft_itoa((int)nbr);
		str_dec = ft_itoa(dec);
		tmp = ft_strjoin(str_int, ".");
		free(str_int);
		str = ft_strjoin(tmp, str_dec);
		free(str_dec);
		free(tmp);
	}
	else
		str = ft_itoa((int)nbr);
	mlx_string_put(fdf->mlx, fdf->win, tab, line, GRAY, str);
	free(str);
}

static void	map_info(t_fdf *fdf)
{
	int	line;

	if (fdf->colorscheme == 0)
		fdf->color_name = "Original";
	line = INFO_LINE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, ORANGE, "+++++MAP INFO+++++");
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Map: ");
	mlx_string_put(fdf->mlx, fdf->win, TAB + 30, line, GRAY, fdf->file);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Projection: ");
	mlx_string_put(fdf->mlx, fdf->win, TAB + 70, line, GRAY, fdf->proj_name);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Colorscheme: ");
	mlx_string_put(fdf->mlx, fdf->win, TAB + 75, line, GRAY, fdf->color_name);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Mode: ");
	mlx_string_put(fdf->mlx, fdf->win, TAB + 35, line, GRAY, fdf->mode_name);
}

static void	map_data(t_fdf *fdf)
{
	int	line;

	line = DATA_LINE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, ORANGE, "+++++MAP DATA+++++");
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Map size:     X");
	win_put_nbr(fdf, TAB + 60, line, fdf->map.width);
	win_put_nbr(fdf, TAB + 105, line, fdf->map.width);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Z max:");
	win_put_nbr(fdf, TAB + 40, line, fdf->map.z_max);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Z min:");
	win_put_nbr(fdf, TAB + 40, line, fdf->map.z_min);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Zoom:");
	win_put_nbr(fdf, TAB + 40, line, fdf->zoom);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, "Z-depth:");
	win_put_nbr(fdf, TAB + 50, line, fdf->map.z_depth);
}

static void	map_controls(t_fdf *fdf)
{
	int	line;

	line = CONTROL_LINE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, ORANGE, CONTROL_TITLE);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, MOVE_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, ROTATE_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, RESET_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, RECENTER_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, PROJECTION_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, COLOR_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, MENU_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, ZOOM_CONTROL);
	line += LINE_SIZE;
	mlx_string_put(fdf->mlx, fdf->win, TAB, line, GRAY, Z_CONTROL);
}

void	render_menu(t_fdf *fdf)
{
	map_info(fdf);
	map_data(fdf);
	map_controls(fdf);
}
