/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:36:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/11 18:37:06 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_map *map)
{
	double	x;
	double	y;

	x = cos(358.0 * M_PI / 180.0) * map->gamer->dirx
	- sin(358.0 * M_PI / 180.0) * map->gamer->diry;
	y = cos(358.0 * M_PI / 180.0) * map->gamer->diry
	+ sin(358.0 * M_PI / 180.0) * map->gamer->dirx;
	map->gamer->dirx = x;
	map->gamer->diry = y;
	x = cos(358.0 * M_PI / 180.0) * map->gamer->planex
	- sin(358.0 * M_PI / 180.0) * map->gamer->planey;
	y = cos(358.0 * M_PI / 180.0) * map->gamer->planey
	+ sin(358.0 * M_PI / 180.0) * map->gamer->planex;
	map->gamer->planex = x;
	map->gamer->planey = y;
}
