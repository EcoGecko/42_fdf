/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:17 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:43:46 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <math.h>
# include "defines.h"
# include "matrix.h"

void	x_rotation(t_point *points, int angle, int size);
void	y_rotation(t_point *points, int angle, int size);
void	z_rotation(t_point *points, int angle, int size);
void	ortho_project(t_point *points, int size);
#endif
