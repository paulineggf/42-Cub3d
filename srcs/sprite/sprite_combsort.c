/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_combsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:36:57 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 18:50:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_combsort(t_map *map)
{
	int		i;
	// int		j;
	void	*add;

	// j = 1;
		i = 0;

	while (i < map->size_sprite - 1)
	{
		if (map->sprite[i]->distance < map->sprite[i + 1]->distance)
		{
			add = map->sprite[i];
			map->sprite[i] = map->sprite[i + 1];
			map->sprite[i + 1] = add;
			i = 0;
		}
		else
			i++;
	}
}
