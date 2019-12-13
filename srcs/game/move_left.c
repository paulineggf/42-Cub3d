/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:32:08 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_left(t_map *map)
{
	double	x;
	double	y;

	if (map->map[(int)(map->gamer.posy + cos(270.0 * M_PI / 180.0)
	* map->gamer.diry + sin(270.0 * M_PI / 180.0) * map->gamer.dirx
	* 0.1)][(int)(map->gamer.posx + (cos(270.0 * M_PI / 180.0)
	* map->gamer.dirx - sin(270.0 * M_PI / 180.0) * map->gamer.diry
	* 0.1))] == 1)
		return (0);
	x = cos(270.0 * M_PI / 180.0) * map->gamer.dirx
	- sin(270.0 * M_PI / 180.0) * map->gamer.diry;
	y = cos(270.0 * M_PI / 180.0) * map->gamer.diry
	+ sin(270.0 * M_PI / 180.0) * map->gamer.dirx;
	map->gamer.posx += x * 0.1;
	map->gamer.posy += y * 0.1;
	return (1);
}
