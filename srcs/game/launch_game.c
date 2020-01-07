/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:54 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/07 10:29:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		launch_game(t_map *map)
{
	mlx_hook(map->ptr.win, 17, 0, close_cross, map);
	mlx_hook(map->ptr.win, 3, 0, release_key, map);
	mlx_hook(map->ptr.win, 2, 0, press_key, map);
	mlx_loop_hook(map->ptr.mlx, init_image, map);
	mlx_loop(map->ptr.mlx);
	return (1);
}
