/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:36:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 16:39:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_map *map, unsigned int *str, int *x)
{
	while (map->gamer->drawstart <= map->gamer->drawend)
	{
		str[((map->ptr->size_l / 4) * map->gamer->drawstart)
		+ *x] = map->ptr->color;
		map->gamer->drawstart += 1;
	}
}
