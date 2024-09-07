/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:02:14 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:25:44 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <math.h>
# include "../libft/libft.h"
# include "defines.h"
# include "error_utils.h"
# include "utils.h"

void	get_points(t_fdf *fdf);
void	map_init(t_fdf *fdf, t_map *map);
void	get_map_size(t_map *map, t_fdf *fdf);
void	load_points(char *set, t_map *map, int y, t_fdf *fdf);
#endif
