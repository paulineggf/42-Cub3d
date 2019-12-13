/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:59:42 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 18:58:28 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_image(t_map *map)
{
	if (!(move_gamer(map)))
		return (0);
	map->ptr.img = mlx_new_image(map->ptr.mlx, RES_X, RES_Y);
	if (!(map->ptr.str = (unsigned int*)mlx_get_data_addr(map->ptr.img,
	&map->ptr.b_p, &map->ptr.size_l, &map->ptr.endian)))
		exit_failure("Malloc failure\n", map);
	fill_str(map);
	mlx_put_image_to_window(map->ptr.mlx,
	map->ptr.win, map->ptr.img, 0, 0);
	return (1);
}
