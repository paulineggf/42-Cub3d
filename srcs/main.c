/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/29 15:48:23 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_pos	*gamer;
	t_map	*map;
	t_win	*ptr;

	if (argc == 2)
	{
		if (!(map = malloc(sizeof(t_map))))
			return (0);
		ft_bzero(map, sizeof(t_map));
		if (!(gamer = malloc(sizeof(t_pos))))
			return (0);
		ft_bzero(gamer, sizeof(t_pos));
	/*	if (!(gamer->unitx = ft_calloc(1, sizeof(int)))
		|| !(gamer->unity = ft_calloc(1, sizeof(int))))
			return (0);*/
		if (!init_map(argv[1], map, gamer))
			return (0);
		if (!(ptr = malloc(sizeof(t_win))))
			return (0);
		ft_bzero(ptr, sizeof(ptr));
	/*	ptr->mlx_ptr = mlx_init();
		ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
		PROJ_PLANE_X, PROJ_PLANE_Y, "Cub3D");*/
		ptr->color = 0xFF6F8F;
		launch_game(map, gamer, ptr);
	}
	return (0);
}
