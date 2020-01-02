/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:56:49 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:53:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_map(char *av, t_map *map)
{
	int		fd;
	char	*tmp;

	if (!ft_strncmp(av, ".", 1))
		exit_failure("Error\nHidden file\n", map);
	if (ft_strcmp(av + ft_strlen(av) - 4, ".cub"))
		exit_failure("Error\nExtension error\n", map);
	if ((fd = open(av, O_RDONLY)) == -1)
		exit_failure("Open file fail\n", map);
	define_params(fd, &tmp, map);
	close(fd);
	malloc_map(map);
	fill_map(tmp, 0, map);
	verif_map(map);
	malloc_sprite(map);
}
