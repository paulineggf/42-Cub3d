/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:56:02 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/04 18:35:48 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_forward(t_map *map)
{
	int		tmp_degree;
	double	tmp_unitx;
	double	tmp_unity;

	tmp_unitx = 0.0;
	tmp_unity = 0.0;
	if (map->gamer->facing_up && map->gamer->facing_right)
		tmp_degree = map->gamer->degree;
	else if (map->gamer->facing_up && map->gamer->facing_left)
		tmp_degree = map->gamer->degree - 90;
	else if (map->gamer->facing_down && map->gamer->facing_left)
		tmp_degree = map->gamer->degree - 180;
	else
		tmp_degree = map->gamer->degree - 360;
	tmp_unitx += 1;
	tmp_unity += 1 / cos(map->gamer->degree * M_PI / 180.0);
	if (map->gamer->facing_up && map->gamer->facing_left)
		tmp_unity /= -1;


/*	if (map->gamer->degree >= 90 && map->gamer->degree < 180)
		x = -1.0;
	if (map->gamer->degree >= 180 && map->gamer->degree < 270)
	{
		x = -1.0;
		y = -1.0;
	}
	if (map->gamer->degree >= 270 && map->gamer->degree < 360)
		y = -1.0;*/


	if (map->map[(int)(map->gamer->unity / BLOCK_SIZE)]
	[(int)(map->gamer->unitx / BLOCK_SIZE)] == 1)
		return (0);
	//map->gamer->unitx = x + map->gamer->unitx;
	//map->gamer->unity = y + map->gamer->unity;
	map->gamer->posx = (int)(map->gamer->unitx / BLOCK_SIZE);
	map->gamer->posy = (int)(map->gamer->unity / BLOCK_SIZE);
	return (1);
}
