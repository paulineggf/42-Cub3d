/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gamer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:30:00 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/04 11:45:35 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_gamer(int key, t_map *map)
{
	if (key == 12)
	{
		map->gamer->unitx = cos(map->gamer->degree * M_PI / 180.0);
		map->gamer->unity = sin(map->gamer->degree * M_PI / 180.0);
		map->gamer->posx = map->gamer->unitx / BLOCK_SIZE;
		map->gamer->posy = map->gamer->unity / BLOCK_SIZE;
	}
	if (key == 6)
	{
		map->gamer->unitx = sin(map->gamer->degree * M_PI / 180.0);
		map->gamer->unity = cos(map->gamer->degree * M_PI / 180.0);
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
}
