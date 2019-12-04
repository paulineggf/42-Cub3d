/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:56:02 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/04 16:17:24 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_forward(t_map *map)
{
	int		x;
	int		y;

	x = 1;
	y = 1;
	if (map->gamer->degree >= 90 && map->gamer->degree < 180)
		x = -1;
	if (map->gamer->degree >= 180 && map->gamer->degree < 270)
	{
		x = -1;
		y = -1;
	}
	if (map->gamer->degree >= 270 && map->gamer->degree < 360)
		y = -1;
	if (map->map[(int)((y + map->gamer->unity) / BLOCK_SIZE)]
	[(int)((x + map->gamer->unitx) / BLOCK_SIZE)] == 1)
		return (0);
	map->gamer->unitx = (double)x + map->gamer->unitx;
	map->gamer->unity = (double)y + map->gamer->unity;
	map->gamer->posx = (int)(map->gamer->unitx / BLOCK_SIZE);
	map->gamer->posy = (int)(map->gamer->unity / BLOCK_SIZE);
	return (1);
}
