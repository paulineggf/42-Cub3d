/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:36:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 16:52:02 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		define_texture(t_map *map, int *texture)
{
	if (map->gamer.side == 0 && map->gamer.raydirx >= 0)
		*texture = EAST;
	else if (map->gamer.side == 0 && map->gamer.raydirx < 0)
		*texture = WEST;
	else if (map->gamer.side == 1 && map->gamer.raydiry < 0)
		*texture = NORTH;
	else
		*texture = SOUTH;
}

void	draw_wall(t_map *map)
{
	int		xtext;
	int		ytext;
	int		i;
	int		texture;

	define_texture(map, &texture);
	ytext = 0;
	if (map->gamer.real_drawstart < 0)
		i = abs(map->gamer.real_drawstart);
	else
		i = 0;
	xtext = map->gamer.wallx * map->text[texture]->x;
	while (map->gamer.drawstart <= map->gamer.drawend)
	{
		if (i * map->text[texture]->y / (int)map->gamer.lineheight
		>= map->text[texture]->y)
			ytext = map->text[texture]->y - 1;
		else
			ytext = i * map->text[texture]->y / (int)map->gamer.lineheight;
		map->ptr.str[((map->ptr.size_l / 4) *
		map->gamer.drawstart) + map->stripe] = map->text[texture]->str[(ytext *
		(map->text[texture]->size_l / 4))
		+ xtext];
		i++;
		map->gamer.drawstart += 1;
	}
	map->zbuffer[map->stripe] = map->gamer.perpwalldist;
}
