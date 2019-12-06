/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isitwall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:45:14 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/05 15:33:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos		*is_wall(t_map *map)
{
	t_pos	*wall_hor;
	t_pos	*wall_ver;

	if (!(wall_hor = malloc(sizeof(t_pos)))
	|| !(wall_ver = malloc(sizeof(t_pos))))
		return (NULL);
	ft_bzero(wall_hor, sizeof(t_pos));
	ft_bzero(wall_ver, sizeof(t_pos));
	wall_ver->ver = 1;
	wall_hor->hor = 1;
	fill_wall_hor(map, wall_hor);
	fill_wall_ver(map, wall_ver);
	return (ft_closer(map, wall_hor, wall_ver));
}
