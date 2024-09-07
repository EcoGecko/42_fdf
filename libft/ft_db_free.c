/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:42 by heda-sil          #+#    #+#             */
/*   Updated: 2023/02/27 17:38:45 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_db_free(char **mat)
{
	int	i;

	i = -1;
	if (mat)
	{
		while (mat[++i])
		{
			if (mat[i])
			{
				free(mat[i]);
				mat[i] = NULL;
			}
		}
		free(mat);
		mat = NULL;
	}
}
