/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:10:40 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 11:25:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//Window size 1920x1080, 1280x720, 720x576, 720x480
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define ZOOM 1.25f
# define SHIFT 5

//Colors
# define WHITE 0xFFFFFF
# define GRAY 0x808080
# define BLACK 0x000000
# define VIOLET 0x9400D3
# define INDIGO 0x4B0082
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define YELLOW 0xFFFF00
# define ORANGE 0xFF7F00
# define RED 0xFF0000
# define NAVY_BLUE 0x000080
# define DARK_GREEN 0x228C22
# define BROWN 0x964B00
# define SANDY_YELLOW 0xFDEE73

typedef struct s_point
{
	float	coord[3];
	int		color;
	int		map_color;
}			t_point;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_colors
{
	int		sea_level;
	int		ground_level;
	int		high_level;
	int		medium_level;
	int		ground_low;
	int		top_level;
	int		sea_low;
}		t_colors;

typedef struct s_map
{
	t_point		*points;
	t_point		*projected;
	t_point		*fitted;
	t_colors	colorscheme;
	int			width;
	int			height;
	int			size;
	float		scale;
	float		z_factor;
	float		z_depth;
	float		z_max;
	float		z_min;
	int			angle[3];
	char		*str_map;
}				t_map;

typedef struct s_line_vars
{
	int		sx;
	int		sy;
	int		dx;
	int		dy;
	int		error;
	float	dist;
	int		len;
	int		color;
}				t_vars;

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	plus;
	int	minus;
	int	comma;
	int	period;
	int	mouse_r;
	int	mouse_l;
	int	help;
}				t_keys;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	char		*file;
	t_img		img;
	t_map		map;
	t_keys		key;
	float		zoom;
	int			projection;
	char		*proj_name;
	int			colorscheme;
	char		*color_name;
	int			mode;
	char		*mode_name;
	int			shift[3];
	int			mouse[2];
	int			point;
	int			inverter;
}				t_fdf;
#endif
