/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:38:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 20:41:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_sky(t_map *map)
{
	int		textx;
	int		y;
	int		ysky;
	int		ground;

	textx = fabs((atan2(map->gamer.raydiry, map->gamer.raydirx)
	/ M_PI) * map->text[SKY]->x);
	ysky = 200;
	y = 0;
	ground = 0x133A30;
	while (y < RES_Y / 2)
	{
		map->ptr.str[((map->ptr.size_l / 4) * y) + map->stripe] =
		map->text[SKY]->str[(((map->text[SKY]->size_l / 4) * ysky)
		+ textx)];
		y++;
		ysky++;
	}
}
