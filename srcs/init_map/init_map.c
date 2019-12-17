/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:56:49 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 18:31:50 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_map(char *av, t_map *map)
{
	int		fd;
	int		ret;
	char	buf[33];
	t_list	*new;
	int		i;

	if ((fd = open(av, O_RDONLY)) == -1)
		exit_failure("Open file fail\n", map);
	define_x(fd, buf, map, &ret);
	if (define_y(fd, buf, map, &ret) == -1)
		ft_close(fd, map);
	close(fd);
	malloc_map(map);
	if ((fd = open(av, O_RDONLY)) == -1)
		exit_failure("Open file fail\n", map);
	if (fill_map(fd, map) == -1)
		return (ft_close(fd, map));
	if (!(map->sprite = malloc(sizeof(t_sprite*) * map->size_sprite)))
		exit_failure("Malloc failure\n", map);
	if (!(new = ft_lstnew(map->sprite)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new);
	i = 0;
	while (i < map->size_sprite)
	{
		easy_malloc((void**)&(map->sprite[i]), sizeof(t_sprite), map);
		i++;
	}
	close(fd);
}
