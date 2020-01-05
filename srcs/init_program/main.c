/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/05 15:12:27 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	end(void) __attribute__ ((destructor));

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2 || (argc == 3 && !ft_strcmp(argv[2], "-save")))
	{
		if (!(map = malloc(sizeof(t_map))))
			return (0);
		ft_bzero(map, sizeof(t_map));
		if (!(map->garbage_collector = malloc(sizeof(t_list))))
			return (0);
		ft_bzero(map->garbage_collector, sizeof(t_list));
		init_map(argv[1], map);
		map->ptr.mlx = mlx_init();
		map->ptr.win = mlx_new_window(map->ptr.mlx,
		map->res_x, map->res_y, "Cub3D");
		malloc_texture(map);
		init_texture(map);
		easy_malloc((void**)&map->zbuffer, sizeof(double) * map->res_x, map);
		map->ptr.img = mlx_new_image(map->ptr.mlx, map->res_x, map->res_y);
		if (!(map->ptr.str = (unsigned int*)mlx_get_data_addr(map->ptr.img,
		&map->ptr.b_p, &map->ptr.size_l, &map->ptr.endian)))
			exit_failure("Malloc failure\n", map);
		if (argc == 2)
			launch_game(map);
		else
			bmp_image(map);
	}
	else if (argc == 3 && ft_strcmp(argv[2], "-save"))
		ft_putstr_fd("Don't recognize the second argument\n", 2);
	else
		ft_putstr_fd("Missing file\n", 2);
	return (0);
}

void	end()
{
 	while (1) ;
}
