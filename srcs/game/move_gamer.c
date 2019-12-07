/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gamer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:13:36 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/07 19:39:44 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_gamer(t_map *map)
{
	double	x;
	double 	y;

	if (map->gamer->av)
	{
		map->gamer->posx = map->gamer->posx + map->gamer->dirx * 0.1;
		map->gamer->posy = map->gamer->posy + map->gamer->diry * 0.1;
	}
	if (map->gamer->re)
	{
		map->gamer->posx = map->gamer->posx - map->gamer->dirx * 0.1;
		map->gamer->posy = map->gamer->posy - map->gamer->diry * 0.1;
	}
	if (map->gamer->ga)
	{
		x = cos(270.0 * M_PI / 180.0) * map->gamer->dirx - sin(270.0 * M_PI / 180.0) * map->gamer->diry;
		y = cos(270.0 * M_PI / 180.0) * map->gamer->diry + sin(270.0 * M_PI / 180.0) * map->gamer->dirx;
		map->gamer->posx += x * 0.1;
		map->gamer->posy += y * 0.1;
	}
	if (map->gamer->dr)
	{
		x = cos(90.0 * M_PI / 180.0) * map->gamer->dirx - sin(90.0 * M_PI / 180.0) * map->gamer->diry;
		y = cos(90.0 * M_PI / 180.0) * map->gamer->diry + sin(90.0 * M_PI / 180.0) * map->gamer->dirx;
		map->gamer->posx += x * 0.1;
		map->gamer->posy += y * 0.1;
	}
	if (map->gamer->rdr)
	{
		x = cos(10.0 * M_PI / 180.0) * map->gamer->dirx - sin(10.0 * M_PI / 180.0) * map->gamer->diry;
		y = cos(10.0 * M_PI / 180.0) * map->gamer->diry + sin(10.0 * M_PI / 180.0) * map->gamer->dirx;
		map->gamer->dirx = x;
		map->gamer->diry = y;
		x = cos(10.0 * M_PI / 180.0) * map->gamer->planex - sin(10.0 * M_PI / 180.0) * map->gamer->planey;
		y = cos(10.0 * M_PI / 180.0) * map->gamer->planey + sin(10.0 * M_PI / 180.0) * map->gamer->planex;
		map->gamer->planex = x;
		map->gamer->planey = y;
	}
	if (map->gamer->rga)
	{
		x = cos(350.0 * M_PI / 180.0) * map->gamer->dirx - sin(350.0 * M_PI / 180.0) * map->gamer->diry;
		y = cos(350.0 * M_PI / 180.0) * map->gamer->diry + sin(350.0 * M_PI / 180.0) * map->gamer->dirx;
		map->gamer->dirx = x;
		map->gamer->diry = y;
		x = cos(350.0 * M_PI / 180.0) * map->gamer->planex - sin(350.0 * M_PI / 180.0) * map->gamer->planey;
		y = cos(350.0 * M_PI / 180.0) * map->gamer->planey + sin(350.0 * M_PI / 180.0) * map->gamer->planex;
		map->gamer->planex = x;
		map->gamer->planey = y;
	}
}
