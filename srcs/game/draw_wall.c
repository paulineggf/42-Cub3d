/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/03 17:32:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Q = 12
** S = 1
** D = 2
** Z = 6
** ESC = 53
*/

int			draw_wall(int key, void *param)
{
	t_map			*map;
	unsigned int	*str;

	printf("%d\n", key);

	map = (t_map*)param;
	if (key == 12)
	{
		map->gamer->unitx--;
		map->gamer->unity--;
		map->gamer->posx = map->gamer->unitx / BLOCK_SIZE;
		map->gamer->posy = map->gamer->unity / BLOCK_SIZE;
	}
	if (key == 6)
	{
		map->gamer->unitx++;
		map->gamer->unity++;
		map->gamer->posx = map->gamer->unitx / BLOCK_SIZE;
		map->gamer->posy = map->gamer->unity / BLOCK_SIZE;
	}
	if (key == 2)
		map->gamer->degree--;
	if (key == 1)
		map->gamer->degree++;
	if (map->gamer->degree < 0)
		map->gamer->degree += 360;
	if (map->gamer->degree > 360)
		map->gamer->degree -= 360;
	if (map->gamer->degree >= 0 && map->gamer->degree < 180)
		map->gamer->facing_up = 1;
	if (map->gamer->degree >= 180 && map->gamer->degree < 360)
		map->gamer->facing_down = 1;
	if (map->gamer->degree <= 90 || map->gamer->degree > 270)
		map->gamer->facing_right = 1;
	if (map->gamer->degree > 90 && map->gamer->degree <= 270)
		map->gamer->facing_left = 1;
	map->ptr->img = mlx_new_image(map->ptr->mlx, PROJ_PLANE_X, PROJ_PLANE_Y);
	str = (unsigned int*)mlx_get_data_addr(map->ptr->img, &map->ptr->b_p,
	&map->ptr->size_l, &map->ptr->endian);
	draw_wall2(map, str);
	mlx_put_image_to_window(map->ptr->mlx,
	map->ptr->win, map->ptr->img, 0, 0);
	return (1);
}
