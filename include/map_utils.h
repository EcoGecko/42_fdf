/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:59:21 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:28:11 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "error_utils.h"
# include "defines.h"

void	validate_filetype(t_fdf *fdf);
void	extract_map(t_map *map, t_fdf *fdf);
void	validate_content(char *point, t_fdf *fdf);
int		get_point_color(char *point);
void	copy_map(t_point *src, t_point *dst, int size);
#endif
