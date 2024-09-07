/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:16:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/17 14:07:35 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//# include "fdf.h"
# include <math.h>
# include "defines.h"
# include "geometry.h"
# include "map_utils.h"
# include "../libft/libft.h"

void	z_scale(t_map *map);
void	z_factoring(t_map *map);
void	parse_map(t_map *map, t_fdf *fdf);
void	fit_map(t_point *fitted, t_fdf *fdf);
#endif
