/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:04:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/05 18:26:32 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	*ft_closer(t_map *map, t_pos *wall_hor, t_pos *wall_ver)
{
	if (wall_hor->posx < 0 || wall_hor->posx >= map->x
	|| wall_hor->posy < 0 || wall_hor->posy >= map->y)
	{
		if ((wall_hor->posx >= 0 && wall_hor->posx < map->x)
		&& (wall_hor->posy >= 0 && wall_hor->posy < map->y))
			printf("I wall_hor->posx : %d\nI wall_hor->posy : %d\n", wall_hor->posx, wall_hor->posy);
		//printf("map->mapx : %d\n", map->x);
		//printf("map->mapy : %d\n", map->y);
		wall_ver->dis = sqrt(pow((double)map->gamer->unitx - (double)wall_ver->unitx, 2.0)
		+ pow((double)map->gamer->unity - (double)wall_ver->unity, 2.0));
		return (free_wall(wall_ver, &wall_hor));
	}
	if (wall_ver->posx < 0 || wall_ver->posx >= map->x
	|| wall_ver->posy < 0 || wall_ver->posy >= map->y)
	{
		if ((wall_ver->posx >= 0 && wall_ver->posx < map->x)
		&& (wall_ver->posy >= 0 && wall_ver->posy < map->y))
			printf("II wall_ver->posx : %d\nII wall_ver->posy : %d\n", wall_ver->posx, wall_ver->posy);
		//printf("map->mapx : %d\n", map->x);
		//printf("map->mapy : %d\n", map->y);
		wall_hor->dis = sqrt(pow((double)map->gamer->unitx - (double)wall_hor->unitx, 2.0)
		+ pow((double)map->gamer->unity - (double)wall_hor->unity, 2.0));
		return (free_wall(wall_hor, &wall_ver));
	}
	wall_hor->dis = pow((double)map->gamer->unitx - (double)wall_hor->unitx, 2.0)
	+ pow((double)map->gamer->unity - (double)wall_hor->unity, 2.0);
	wall_ver->dis = pow((double)map->gamer->unitx - (double)wall_ver->unitx, 2.0)
	+ pow((double)map->gamer->unity - (double)wall_ver->unity, 2.0);
	if (map->gamer->beta == 30)
	{
	if (wall_hor->dis == wall_ver->dis)
	{
		printf("equal dis : %f && %f\n", wall_hor->dis, wall_ver->dis);
	}
	}
	if (wall_hor->dis < wall_ver->dis)
	{
		wall_hor->dis = sqrt(wall_hor->dis);
		return (free_wall(wall_hor, &wall_ver));
	}
	wall_ver->dis = sqrt(wall_ver->dis);
	return (free_wall(wall_ver, &wall_hor));
}
