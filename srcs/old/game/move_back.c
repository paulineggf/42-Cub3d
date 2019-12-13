/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:57:33 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_back(t_map *map)
{
	double	x;
	double	y;

	x = 1.0;
	y = 1.0;
	if (map->gamer.degree >= 0 && map->gamer.degree < 90)
	{
		x = -1.0;
		y = -1.0;
	}
	if (map->gamer.degree >= 90 && map->gamer.degree < 180)
		y = -1.0;
	if (map->gamer.degree >= 270 && map->gamer.degree < 360)
		x = -1.0;
	if (map->map[(int)((y + map->gamer.unity) / BLOCK_SIZE)]
	[(int)((x + map->gamer.unitx) / BLOCK_SIZE)] == 1)
		return (0);
	map->gamer.unitx = (double)x + map->gamer.unitx;
	map->gamer.unity = (double)y + map->gamer.unity;
	map->gamer.posx = (int)(map->gamer.unitx / BLOCK_SIZE);
	map->gamer.posy = (int)(map->gamer.unity / BLOCK_SIZE);
	return (1);
}
