/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:14 by heda-sil          #+#    #+#             */
/*   Updated: 2023/02/17 20:30:33 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_MOUSE_H
# define CONTROL_MOUSE_H

# include "defines.h"
# include "render.h"

int	button_press(int button, int x, int y, void *param);
int	button_release(int button, int x, int y, void *param);
int	mouse_pos(int x, int y, void *param);
#endif
