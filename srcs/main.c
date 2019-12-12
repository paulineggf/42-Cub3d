/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 16:48:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	t_list	*garbage_collector;

	if (argc == 2)
	{
		if (!(map = malloc(sizeof(t_map))))
			return (0);
		ft_bzero(map, sizeof(t_map));
		garbage_collector = NULL;
		if (!(garbage_collector = malloc(sizeof(t_list))))
			return (0);
		ft_bzero(garbage_collector, sizeof(t_list));
		map->garbage_collector = garbage_collector;
		easy_malloc((void*)&(map->ptr), sizeof(t_win), map);
		easy_malloc((void*)&(map->gamer), sizeof(t_pos), map);
		init_map(argv[1], map);
		map->ptr->mlx = mlx_init();
		map->ptr->win = mlx_new_window(map->ptr->mlx,
		RES_X, RES_Y, "Cub3D");
		init_texture(map);
		launch_game(map);
	}
	return (0);
}
