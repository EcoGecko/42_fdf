/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:27:33 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 09:59:10 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "defines.h"

# define LINE_SIZE 20
# define TAB 30
# define INFO_LINE 40
# define DATA_LINE 140
# define CONTROL_LINE 260
# define CONTROL_TITLE "+++++CONTROLS+++++"
# define ROTATE_CONTROL "Rotate: Right click + Drag"
# define MOVE_CONTROL "Move: WASD | Arrow Keys | Left click + Drag"
# define RESET_CONTROL "Reset all: R"
# define RECENTER_CONTROL "Recenter map: HOME"
# define PROJECTION_CONTROL "Cycle projection: P"
# define COLOR_CONTROL "Cycle colorscheme: C"
# define MENU_CONTROL "Toggle menu: H"
# define ZOOM_CONTROL "Zoom in/out: Scroll in/out | +/-"
# define Z_CONTROL "Increase/Decrease Z-depth: </>"

void	render_menu(t_fdf *fdf);
#endif
