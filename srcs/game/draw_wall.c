/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:36:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/10 19:25:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_map *map, unsigned int *str, int *x)
{
	init_texture(map);
	while (map->gamer->drawstart <= map->gamer->drawend)
	{
		str[((map->ptr->size_l / 4) * map->gamer->drawstart)
		+ *x] = map->text->str[(int)(((map->text->size_l / 4) * (map->gamer->wallx * 64)) + (64 / map->gamer->drawstart))];
		map->gamer->drawstart += 1;
	}
	/*while (map->gamer->drawstart <= map->gamer->drawend)
	{
		str[((map->ptr->size_l / 4) * map->gamer->drawstart)
		+ *x] = map->ptr->color;
		map->gamer->drawstart += 1;
	}*/
}
