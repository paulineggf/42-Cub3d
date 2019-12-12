/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:59:42 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 16:39:45 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		refresh(t_map *map)
{
	if (!(move_gamer(map)))
		return (0);
	map->ptr->img = mlx_new_image(map->ptr->mlx, RES_X, RES_Y);
	map->ptr->str = (unsigned int*)mlx_get_data_addr(map->ptr->img,
	&map->ptr->b_p, &map->ptr->size_l, &map->ptr->endian);
	fill_str(map);
	mlx_put_image_to_window(map->ptr->mlx,
	map->ptr->win, map->ptr->img, 0, 0);
	return (1);
}
