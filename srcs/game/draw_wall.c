/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:36:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:02:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		define_texture(t_map *map)
{
	if (map->gamer.side == 0 && map->gamer.raydirx >= 0)
		map->text.str = map->text.str_e;
	else if (map->gamer.side == 0 && map->gamer.raydirx < 0)
		map->text.str = map->text.str_w;
	else if (map->gamer.side == 1 && map->gamer.raydiry < 0)
		map->text.str = map->text.str_n;
	else
		map->text.str = map->text.str_s;
}

void	draw_wall(t_map *map, int *x)
{
	int		xtext;
	int		ytext;
	int		i;

	define_texture(map);
	ytext = 0;
	if (map->gamer.real_drawstart < 0)
		i = abs(map->gamer.real_drawstart);
	else
		i = 0;
	xtext = map->gamer.wallx * map->text.x;
	while (map->gamer.drawstart <= map->gamer.drawend)
	{
		if (i * map->text.y / (int)map->gamer.lineheight >= map->text.y)
			ytext = map->text.y - 1;
		else
			ytext = i * map->text.y / (int)map->gamer.lineheight;
		map->ptr.str[((map->ptr.size_l / 4) * map->gamer.drawstart)
		+ *x] = map->text.str[(ytext * (map->text.size_l / 4)) + xtext];
		i++;
		map->gamer.drawstart += 1;
	}
}
