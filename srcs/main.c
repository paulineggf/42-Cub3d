/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/06 17:42:43 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		if (!(map = malloc(sizeof(t_map))))
			return (0);
		ft_bzero(map, sizeof(t_map));
		if (!(map->ptr = malloc(sizeof(t_win)))
		|| !(map->gamer = malloc(sizeof(t_pos))))
			return (0);
		ft_bzero(map->gamer, sizeof(t_pos));
		ft_bzero(map->ptr, sizeof(t_win));
		if (!init_map(argv[1], map))
			return (0);
		map->ptr->mlx = mlx_init();
		map->ptr->win = mlx_new_window(map->ptr->mlx,
		RES_X, RES_Y, "Cub3D");
		launch_game(map);
	}
	return (0);
}
