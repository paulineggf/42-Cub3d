/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:04:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/04 12:23:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	*ft_closer(t_map *map, t_pos *wall_hor, t_pos *wall_ver)
{
	wall_hor->dis = pow(map->gamer->unitx - wall_hor->unitx, 2)
	+ pow(map->gamer->unity - wall_hor->unity, 2);
	wall_ver->dis = pow(map->gamer->unitx - wall_ver->unitx, 2)
	+ pow(map->gamer->unity - wall_ver->unity, 2);
	if (wall_hor->dis < wall_ver->dis)
	{
		wall_hor->dis = sqrt(wall_hor->dis);
		return (free_wall(wall_hor, &wall_ver));
	}
	wall_ver->dis = sqrt(wall_ver->dis);
	return (free_wall(wall_ver, &wall_hor));
}
