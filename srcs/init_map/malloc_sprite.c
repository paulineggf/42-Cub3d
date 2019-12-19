/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:09:25 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 11:10:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_sprite(t_map *map)
{
	t_list	*new;

	if (!(map->sprite = malloc(sizeof(t_sprite*) * map->size_sprite)))
		exit_failure("Malloc failure\n", map);
	if (!(new = ft_lstnew(map->sprite)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new);
	while (map->size_sprite > 0)
	{
		map->size_sprite--;
		easy_malloc((void**)&(map->sprite[map->size_sprite]),
		sizeof(t_sprite), map);
	}
}
