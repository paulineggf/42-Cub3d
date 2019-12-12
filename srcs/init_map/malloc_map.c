/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:14:09 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 18:43:33 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		malloc_map(t_map *map)
{
	int		i;
	t_list	*new;

	if (!(map->map = malloc(sizeof(int*) * map->y)))
		exit_failure("Malloc failure\n", map);
	if (!(new = ft_lstnew(map->map)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new);
	i = map->y;
	while (i-- > 0)
		easy_malloc((void**)&map->map[i], sizeof(int) * map->x, map);
	// if (!(map->gamer->sprite = sizeof(int*) * map->gamer->size_sprite))
	// 	return (0);
	// i = map->gamer->size_sprite;
	// while (i-- > 0) 
	// {
	// 	if (!(map->gamer->sprite[i] = malloc(sizeof(int) * 2)))
	// 		return (0);
	// 	ft_bzero(map->gamer->sprite[i], sizeof(int) * 2);
	// }
}
