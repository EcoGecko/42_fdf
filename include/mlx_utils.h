/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:55:48 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:29:27 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../mlx/mlx.h"
# include "defines.h"

void	img_put_pix(t_img *img, int x, int y, int color);
int		handle_image(t_fdf *fdf);
#endif
