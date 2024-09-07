/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:07:37 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:10:02 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H

# include <stdio.h>
# include "defines.h"
# include <stdlib.h>
# include "render.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define ERROR_ARGS "Incorrect number of arguments, usage: ./fdf <filename>"
# define ERROR_OPEN "Failed to open the file"
# define ERROR_LINE "Invalid map, the selected map lines have different length"
# define NULL_MAP "Invalid map, the selected map is empty or wrongly formatted"
# define ERROR_TYPE "Invalid filetype, map must be a fdf file"
# define WIN_ERR "Error while handling mlx window"
# define IMG_ERR "Error while handling mlx image"

void	fdf_init(t_fdf *fdf);
void	initializer(t_fdf *fdf, int reset);
void	terminate(t_fdf *prog, char *str, int exit_status, int system);
void	terminate_prog(t_fdf *prog, int exit_status);
int		exit_hook(void	*prog);
#endif
