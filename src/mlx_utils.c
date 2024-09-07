/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:55:38 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:28:59 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

/*Replacement of mlx_pixel_put, this function sets the bits on the image instead
of putting the pixel directly on the display which may cause flickering when
trying to render backgrounds for example*/
void	img_put_pix(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return ;
	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (char)((color >> i) & 0xFF);
		else
			*pixel++ = (char)((color >> (img->bits_per_pixel - 8 - i)) & 0xFF);
		i -= 8;
	}
}

/*Clears old image so I can update the map*/
int	handle_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img.img)
		return (0);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
	&fdf->img.line_length, &fdf->img.endian);
	return (1);
}
