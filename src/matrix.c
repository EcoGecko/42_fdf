/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:40:08 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:40:22 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*Initializes a 3x3 matrix*/
void	init_matrix(float (*matrix)[3])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			matrix[i][j] = 0;
	}
}

/*Multiples 2 3x3 matrix*/
t_point	matrix_mult(float (*matrix)[3], t_point point)
{
	int		i;
	int		j;
	t_point	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.coord[i] = 0;
		result.color = point.color;
		j = 0;
		while (j < 3)
		{
			result.coord[i] += matrix[i][j] * point.coord[j];
			j++;
		}
		i++;
	}
	return (result);
}
