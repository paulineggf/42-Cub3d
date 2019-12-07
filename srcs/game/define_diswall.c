/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_diswall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:23:52 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/07 19:25:20 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_diswall(t_map *map, int side, int mapx, int mapy)
{
/*	printf("stepx : %d\n", map->gamer->stepx);
	printf("stepy : %d\n", map->gamer->stepy);
	printf("raydirx : %f\n", map->gamer->raydirx);
	printf("raydiry : %f\n", map->gamer->raydiry);
	printf("mapy : %d\n", mapy);*/
	if (side == 0)
		map->gamer->perpwalldist =
		((double)mapx - (double)map->gamer->posx
		+ ((1.0 - (double)map->gamer->stepx) / 2.0)) / map->gamer->raydirx;
	else
		map->gamer->perpwalldist =
		((double)mapy - (double)map->gamer->posy
		+ ((1.0 - (double)map->gamer->stepy) / 2.0)) / map->gamer->raydiry;


/*	if (side == 1)
	{
		printf("%d - %f = %f\n", mapy, (double)map->gamer->posy, (double)(mapy - (double)map->gamer->posy));
		printf("1.0 - %f = %f\n", (double)map->gamer->stepy, 1.0 - (double)map->gamer->stepy);
		printf("1.0 - %f / 2.0 = %f\n", (double)map->gamer->stepy, (1.0 - (double)map->gamer->stepy) / 2.0);
		printf("1.0 - %f / 2.0  / %f = %f\n", (double)map->gamer->stepy, map->gamer->raydiry, ((1.0 - (double)map->gamer->stepy) / 2.0) / map->gamer->raydiry);
	}
	if (side == 0)
	{
		printf("%d - %f = %f\n", mapx, (double)map->gamer->posx, (double)(mapx - (double)map->gamer->posx));
		printf("1.0 - %f = %f\n", (double)map->gamer->stepx, 1.0 - (double)map->gamer->stepx);
		printf("1.0 - %f / 2.0 = %f\n", (double)map->gamer->stepx, (1.0 - (double)map->gamer->stepx) / 2.0);
		printf("1.0 - %f / 2.0  / %f = %f\n", (double)map->gamer->stepx, map->gamer->raydirx, ((1.0 - (double)map->gamer->stepx) / 2.0) / map->gamer->raydirx);
	}*/


}
