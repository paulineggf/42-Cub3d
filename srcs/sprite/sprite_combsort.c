/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_combsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:36:57 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 20:54:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reverse(t_map *map, int *i)
{
	int		tmp_mapx;
	int		tmp_mapy;
	double	tmp_distance;

	tmp_mapx = map->sprite[*i]->mapx;
	map->sprite[*i]->mapx = map->sprite[*i + 1]->mapx;
	map->sprite[*i + 1]->mapx = tmp_mapx;
	tmp_mapy = map->sprite[*i]->mapy;
	map->sprite[*i]->mapy = map->sprite[*i + 1]->mapy;
	map->sprite[*i + 1]->mapy = tmp_mapy;
	tmp_distance = map->sprite[*i]->distance;
	map->sprite[*i]->distance = map->sprite[*i + 1]->distance;
	map->sprite[*i + 1]->distance = tmp_distance;
}

void		sprite_combsort(t_map *map)
{
	int		i;
	// void	*add;

	i = 0;
	while (i < map->size_sprite - 1)
	{
		if (map->sprite[i]->distance < map->sprite[i + 1]->distance)
		{
			reverse(map, &i);
			// add = map->sprite[i];
			// map->sprite[i] = map->sprite[i + 1];
			// map->sprite[i + 1] = add;
			i = 0;
		}
		else
			i++;
	}
}
