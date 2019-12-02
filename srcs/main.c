/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 16:08:44 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
//	t_pos	*gamer;
	t_map	*map;
//	t_win	*ptr;

	if (argc == 2)
	{
		if (!(map = malloc(sizeof(t_map))))
			return (0);


		ft_bzero(map, sizeof(t_map));
		if (!(map->ptr = malloc(sizeof(t_win))))
			return (0);
		if (!(map->gamer = malloc(sizeof(t_pos))))
			return (0);

		ft_bzero(map->gamer, sizeof(t_pos));
		ft_bzero(map->ptr, sizeof(t_win));
	
//		if (!(gamer = malloc(sizeof(t_pos))))
//			return (0);
//		ft_bzero(gamer, sizeof(t_pos));
		if (!init_map(argv[1], map, map->gamer))
			return (0);
//		if (!(ptr = malloc(sizeof(t_win))))
//			return (0);
//		
		map->ptr->mlx_ptr = mlx_init();
		map->ptr->win_ptr = mlx_new_window(map->ptr->mlx_ptr,
		PROJ_PLANE_X, PROJ_PLANE_Y, "Cub3D");
		map->ptr->color = 0xFF6F8F;
		launch_game(map);
	}
	return (0);
}
