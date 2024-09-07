/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:20:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/02/16 12:32:37 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_KEYS_H
# define CONTROL_KEYS_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "render.h"
# include "error_utils.h"
# include "defines.h"

int		key_press(int key, void *param);
int		key_release(int key, void *param);
void	apply_keys(t_fdf *fdf);
void	set_keys(int key, t_fdf *fdf, int value);
void	init_keys(t_fdf *fdf);
#endif
