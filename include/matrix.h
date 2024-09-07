/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:40:38 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:43:08 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "defines.h"

void	init_matrix(float (*matrix)[3]);
t_point	matrix_mult(float (*matrix)[3], t_point point);
#endif
