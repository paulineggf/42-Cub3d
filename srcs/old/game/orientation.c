/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:54:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/05 17:16:11 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation(t_map *map)
{
	if (map->gamer->degree >= 0 && map->gamer->degree < 180)
		map->gamer->facing_up = 1;
	else
		map->gamer->facing_up = 0;
	if (map->gamer->degree >= 180 && map->gamer->degree < 360)
		map->gamer->facing_down = 1;
	else
		map->gamer->facing_down = 0;
	if (map->gamer->degree <= 90 || map->gamer->degree > 270)
		map->gamer->facing_right = 1;
	else
		map->gamer->facing_right = 0;
	if (map->gamer->degree > 90 && map->gamer->degree <= 270)
		map->gamer->facing_left = 1;
	else
		map->gamer->facing_left = 0;
}
