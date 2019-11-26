/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/26 18:48:33 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// A FAIRE : mettre posx et posy dans fill_map

int		main(int argc, char **argv)
{
	t_pos	*gamer;
	t_map	*map;

	if (argc == 2)
	{
		if (!(map = malloc(sizeof(t_map))))
			return (0);
		ft_bzero(map, sizeof(t_map));
		if (!(gamer = malloc(sizeof(t_pos))))
			return (0);
		ft_bzero(gamer, sizeof(t_pos));
		if (!init_map(argv[1], map, gamer))
			return (0);
		printf("gamer->x : %d\ngamer->y : %d\n", gamer->posx, gamer->posy);
		//gamer = init_pos(map);
	}
	return (0);
}
