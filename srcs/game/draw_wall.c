/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/03 12:28:02 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			draw_wall2(t_map *map, unsigned int *str)
{
	t_pos	*wall;
	int		tmp;
	double	degree;

	degree = map->gamer->degree;
	map->gamer->degree += 30.0;
	map->ptr->x = 0;
	map->gamer->beta = 30.0;
	while (map->ptr->x <= PROJ_PLANE_X)
	{
		if (!(wall = is_wall(map)))
			return (0);
		wall->slice_height = (double)(BLOCK_SIZE)
		/ (wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0)))
		* (map->dis_proj_plane);
		map->ptr->y = (PROJ_PLANE_Y / 2) - (wall->slice_height / 2);
		if (map->ptr->y < 0 || map->ptr->y > PROJ_PLANE_Y)
			map->ptr->y = 0;
		tmp = map->ptr->y;
		while (map->ptr->y <= tmp + wall->slice_height
		&& map->ptr->y < PROJ_PLANE_Y)
			str[(PROJ_PLANE_X * map->ptr->y++) + map->ptr->x + map->ptr->size_l / 4] = map->ptr->color;

		//	ft_memcpy(str + (map->ptr->size_l / 4 * map->ptr->x)
		//	+ map->ptr->y++, &map->ptr->color, 4);
		map->gamer->degree -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->gamer->beta -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->ptr->x += 1;
		free(wall);
		wall = NULL;
	}
	map->gamer->degree = degree;
	return (1);
}

int			draw_wall(int key, void *param)
{
	t_map			*map;
	unsigned int	*str;

	map = (t_map*)param;
	map->ptr->img = mlx_new_image(map->ptr->mlx, PROJ_PLANE_X, PROJ_PLANE_Y);
	str = (unsigned int*)mlx_get_data_addr(map->ptr->img, &map->ptr->b_p,
	&map->ptr->size_l, &map->ptr->endian);
	draw_wall2(map, str);
	mlx_put_image_to_window(map->ptr->mlx,
	(void*)&key, map->ptr->img, 0, 0);
	return (1);
}

/*int			draw_wall(int key, void *param)
{
	t_map	*map;
	t_pos	*wall;
	int		begin;
	int		tmp;

	map = (t_map*)param;
	map->gamer->degree += 30.0;
	map->ptr->x = 0;
	map->gamer->beta = 30.0;
	while (map->ptr->x <= PROJ_PLANE_X)
	{
		if (!(wall = is_wall(map)))
			return (0);
		wall->slice_height = (double)(BLOCK_SIZE)
		/ (wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0)))
		* (map->dis_proj_plane);
		begin = (PROJ_PLANE_Y / 2) - (wall->slice_height / 2);
		if (begin < 0 || begin > PROJ_PLANE_Y)
			begin = 0;
		tmp = begin;
		while (begin <= tmp + wall->slice_height && begin < PROJ_PLANE_Y)
			mlx_pixel_put((void*)&key, map->ptr->win_ptr,
			map->ptr->x, begin++, map->ptr->color);
		map->gamer->degree -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->gamer->beta -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->ptr->x += 1;
		free(wall);
		wall = NULL;
	}
	return (1);
}
*/