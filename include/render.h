/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:28:50 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:11:22 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "defines.h"
# include "error_utils.h"
# include "mlx_utils.h"
# include "control_keys.h"
# include "draw.h"
# include "utils.h"
# include "menu.h"

int		render(t_fdf *fdf);
void	set_mode(t_fdf *fdf);
void	set_projection(t_fdf *fdf);
void	set_colorscheme(t_fdf *fdf);
void	set_color(t_fdf *fdf, t_map *map);
#endif
