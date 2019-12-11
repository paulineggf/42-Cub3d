/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:36:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/11 14:25:59 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_map *map, unsigned int *str, int *x)
{
	int	xtext;
	int	ytext = 0;
	int	i = 0;
	int	size_l;

	xtext = map->gamer->wallx * map->text->x;
	size_l = map->text->size_l / 4;
	while (map->gamer->drawstart <= map->gamer->drawend)
	{
		if (i * map->text->y / (int)map->gamer->lineheight >= map->text->y)
			ytext = map->text->y - 1;
		else
			ytext = i * map->text->y / (int)map->gamer->lineheight;

		str[((map->ptr->size_l / 4) * map->gamer->drawstart)
		+ *x] =
		map->text->str[(ytext * size_l) + xtext];

		i++;
		map->gamer->drawstart += 1;
	}

/*	while (map->gamer->drawstart <= map->gamer->drawend)
	{
		str[((map->ptr->size_l / 4) * map->gamer->drawstart)
		+ *x] = map->ptr->color;
		map->gamer->drawstart += 1;
	}*/

}
