/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:38:34 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/03 11:37:34 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_sky(t_map *map)
{
	int		textx;
	int		y;
	int		ysky;

	textx = fabs((atan2(map->gamer.raydiry, map->gamer.raydirx)
	/ M_PI) * map->text[SKY]->x);
	ysky = 200 + map->gamer.tmp_jump;
	y = 0;
	while (y < (map->res_y / 2) + map->gamer.tmp_jump)
	{
		map->ptr.str[((map->ptr.size_l / 4) * y) + map->stripe] =
		map->text[SKY]->str[(((map->text[SKY]->size_l / 4) * ysky)
		+ textx)];
		y++;
		ysky++;
	}
}
