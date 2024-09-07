/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 10:26:38 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

/*Get map from file to an array, length of array elems minus newlines and 
spaces will get me the map length*/
void	validate_filetype(t_fdf *fdf)
{
	size_t	length;
	size_t	ext_length;
	char	*ext;

	ext = ".fdf";
	length = ft_strlen(fdf->file);
	ext_length = ft_strlen(ext);
	if (ft_strncmp(fdf->file + (length - ext_length), ext, ext_length))
		terminate(fdf, ERROR_TYPE, 1, 0);
}

/*gets map from an fdf file*/
void	extract_map(t_map *map, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	*aux_map;

	fd = open(fdf->file, O_RDONLY);
	if (fd < 0)
		terminate(fdf, ERROR_OPEN, 1, 1);
	line = get_next_line(fd);
	while (line)
	{
		aux_map = ft_strjoin(map->str_map, line);
		free(map->str_map);
		free(line);
		map->str_map = aux_map;
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	validate_filetype(fdf);
	if (!*map->str_map)
		terminate(fdf, NULL_MAP, 1, 0);
}

/*To validate the content of each point they can have the following format 
"Z-value,HEX-color(0x)"*/
void	validate_content(char *point, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (point[i])
	{
		if (point[i] == '-' && ft_isdigit(point[i + 1]))
			i++;
		else if (ft_isdigit(point[i]))
			i++;
		else if (point[i] == ',' && point[i + 1] == '0' && \
		point[i + 2] == 'x')
			i += 3;
		else if (ft_strchr("0123456789ABCDEF", point[i]))
			i++;
		else if (ft_strchr("0123456789abcdef", point[i]))
			i++;
		else
			terminate(fdf, NULL_MAP, 1, 0);
	}
}

int	get_point_color(char *point)
{
	int		i;
	int		hex;
	char	*exists;
	char	**splitted;

	splitted = ft_split(point, ',');
	if (!splitted[1])
		hex = -1;
	else
		hex = 0;
	i = 0;
	while (splitted[1] && ft_strchr("0x", splitted[1][i]))
		i++;
	while (splitted[1] && splitted[1][i])
	{
		splitted[1][i] = ft_toupper(splitted[1][i]);
		exists = ft_strchr("0123456789ABCDEF", splitted[1][i]);
		if (exists)
			hex = hex * 16 + (16 - ft_strlen(exists));
		else
			break ;
		i++;
	}
	ft_db_free(splitted);
	return (hex);
}

/*Copies map to a new struct*/
void	copy_map(t_point *src, t_point *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}
