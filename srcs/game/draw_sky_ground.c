/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_ground.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:38:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:02:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky_ground(t_map *map, int *x)
{
	int		textx;
	int		y;
	int		ysky;
	int		ground;

	textx = fabs((atan2(map->gamer.raydiry, map->gamer.raydirx)
	/ M_PI) * map->text.sky_x);
	ysky = 200;
	y = 0;
	ground = 0x133A30;
	while (y < RES_Y / 2)
	{
		map->ptr.str[((map->ptr.size_l / 4) * y) + *x] = map->text.sky[
		(((map->text.size_l_sky / 4) * ysky)
		+ textx)];
		y++;
		ysky++;
	}
	while (y < RES_Y)
		map->ptr.str[((map->ptr.size_l / 4) * y++) + *x] = ground;
}
