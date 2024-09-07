/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:17:55 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:39:55 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

/*Performs x-axis rotation*/
void	x_rotation(t_point *points, int angle, int size)
{
	int		i;
	float	radian;
	float	matrix[3][3];

	radian = (float)(angle * M_PI / 180);
	init_matrix(matrix);
	matrix[0][0] = 1;
	matrix[1][1] = cosf(radian);
	matrix[1][2] = -sinf(radian);
	matrix[2][1] = sinf(radian);
	matrix[2][2] = cosf(radian);
	i = -1;
	while (++i < size)
		points[i] = matrix_mult(matrix, points[i]);
}

/*Performs y-axis rotation*/
void	y_rotation(t_point *points, int angle, int size)
{
	int		i;
	float	radian;
	float	matrix[3][3];

	radian = (float)(angle * M_PI / 180);
	init_matrix(matrix);
	matrix[0][0] = cosf(radian);
	matrix[0][2] = sinf(radian);
	matrix[1][1] = 1;
	matrix[2][0] = -sinf(radian);
	matrix[2][2] = cosf(radian);
	i = -1;
	while (++i < size)
		points[i] = matrix_mult(matrix, points[i]);
}

/*performs z-axis rotation*/
void	z_rotation(t_point *points, int angle, int size)
{
	int		i;
	float	radian;
	float	matrix[3][3];

	radian = (float)(angle * M_PI / 180);
	init_matrix(matrix);
	matrix[0][0] = cosf(radian);
	matrix[0][1] = -sinf(radian);
	matrix[1][0] = sinf(radian);
	matrix[1][1] = cosf(radian);
	matrix[2][2] = 1;
	i = -1;
	while (++i < size)
		points[i] = matrix_mult(matrix, points[i]);
}

/*Performs orthogonal projection, projects 3D points into a 2D space*/
void	ortho_project(t_point *points, int size)
{
	int		i;
	float	matrix[3][3];

	init_matrix(matrix);
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	i = -1;
	while (++i < size)
		points[i] = matrix_mult(matrix, points[i]);
}
