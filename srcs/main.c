/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:25:18 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 15:44:51 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (!(gamer->unitx = ft_calloc(1, sizeof(int)))
		|| !(gamer->unity = ft_calloc(1, sizeof(int))))
			return (0);
		if (!init_map(argv[1], map, gamer))
			return (0);
		gamer->degree = 45;
		launch_game(map, gamer);
	}
	return (0);
}
