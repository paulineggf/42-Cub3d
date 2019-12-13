/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	*free_wall(t_pos *ret, t_pos **wall, t_map *map)
{
//	printf("map->hor : %d\n", map->hor);
if (map->gamer.beta < 30 && map->gamer.beta > 29.50) 
{
	if (ret->hor)
		printf("dis->hor : %f\n", sqrt(pow((double)map->gamer.unitx - (double)ret->unitx, 2.0)
		+ pow((double)map->gamer.unity - (double)ret->unity, 2.0)));
	else if (ret->ver)
		printf("dis->ver : %f\n", sqrt(pow((double)map->gamer.unitx - (double)ret->unitx, 2.0)
		+ pow((double)map->gamer.unity - (double)ret->unity, 2.0)));
	if ((*wall)->hor)
		printf("dis->hor : %f\n", sqrt(pow((double)map->gamer.unitx - (double)((*wall)->unitx), 2.0)
		+ pow((double)map->gamer.unity - ((double)(*wall)->unity), 2.0)));
	else if ((*wall)->ver)
		printf("dis->ver : %f\n", sqrt(pow((double)map->gamer.unitx - ((double)(*wall)->unitx), 2.0)
		+ pow((double)map->gamer.unity - ((double)(*wall)->unity), 2.0)));
}


	if (ret->hor)
		map->hor = 1;
	else
		map->hor = 0;
	if (ret->ver)
		map->ver = 1;
	else
		map->ver = 0;
	free(*wall);
	*wall = NULL;
	return (ret);
}
