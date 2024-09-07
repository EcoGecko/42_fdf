/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:05:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 09:33:09 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <math.h>
# include "../mlx/mlx.h"
# include "mlx_utils.h"
# include "defines.h"

int		gradient(int star_color, int end_color, int len, int pos);
void	draw_line(t_point p0, t_point p1, t_img *img);
void	wired(t_fdf *fdf, t_point *fitted);
void	doted(t_fdf *fdf, t_point *fitted);
#endif
