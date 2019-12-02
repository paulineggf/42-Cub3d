/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 15:35:28 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			draw_wall(int key, void *param)
{
	t_map	*map;
	t_pos	*gamer;
	t_win	*ptr;
	t_pos	*wall;
	float	begin;
	float	tmp;

	(void)key;
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	ft_memcpy(map, (t_map*)param, sizeof(t_map));
//	map = (t_map*)param;
	gamer = (t_pos*)map->gamer;
	ptr = (t_win*)map->ptr;
	gamer->beta = 30;
	gamer->degree += 30;
	while (gamer->beta >= -30)
	{
		if (!(wall = is_wall(map, gamer)))
			return (0);
		wall->slice_height = roundf(((float)(BLOCK_SIZE)
		/ (float)(dis_wall(gamer, wall)) * (float)(map->dis_proj_plane)));
		begin = PROJ_PLANE_Y - (wall->slice_height / 2);
		tmp = begin;
		while (begin <= tmp + wall->slice_height)
			mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr,
			wall->posx, begin++, ptr->color);
		gamer->beta--;
		gamer->degree--;
	}
	return (1);
}

/*void		draw_wall(int slice_height, t_win *ptr, t_pos *wall)
{
	int		begin;

	begin = PROJ_PLANE_Y - (slice_height / 2);
	while (begin <= begin + slice_height)
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr,
		wall->posx, begin++, ptr->color);
}
*/