/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:29:24 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/03 18:40:48 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	header(char *bmp, int size, t_map *map)
{
	bmp[0] = 0x42;
	bmp[1] = 0x4d;
	*((int*)(bmp + 2)) = size;
	bmp[10] = 0x36;
	bmp[14] = 0x28;
	*((int*)(bmp + 18)) = map->res_x;
	*((int*)(bmp + 22)) = map->res_y;
	bmp[26] = 0x01;
	bmp[28] = 24;
	bmp[34] = 0x24;
	*((int*)(bmp + 38)) = map->res_x;
	*((int*)(bmp + 42)) = map->res_y;
}

static void	fill_pixel(char *bmp, int zero, t_map *map, int size)
{
	int x;
	int y;
	int fd;
	int i;

	i = size - 1;
	y = 0;
	while (i >= 54)
	{
		i -= zero;
		x = map->ptr.size_l - 1;
		while (x >= 0)
		{
			if (x % 4 != 3)
				bmp[i--] = *((char*)(map->ptr.str)
				+ ((map->ptr.size_l * y) + x));
			x--;
		}
		y++;
	}
	fd = open("image.bmp", O_CREAT);
	close(fd);
	fd = open("image.bmp", O_WRONLY);
	write(fd, bmp, size);
	close(fd);
}

void		bmp_image(t_map *map)
{
	char	*bmp;
	int		zero;
	int		size;
	int		l_bmp;

	zero = 0;
	l_bmp = (map->ptr.size_l / 4) * 3;
	while ((((double)l_bmp + (double)zero) / 4.0)
	- (floor(((double)l_bmp + (double)zero) / 4.0)) != 0)
		zero++;
	size = ((l_bmp + zero) * map->res_y) + 54;
	easy_malloc((void**)&bmp, sizeof(char) * size, map);
	fill_str(map);
	header(bmp, size, map);
	fill_pixel(bmp, zero, map, size);
	exit_failure("The image has been saved.\n", map);
}
