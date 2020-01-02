/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:20:26 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:03:58 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_texture(t_map *map)
{
	int		i;
	t_list	*new;

	if (!(map->text = malloc(sizeof(t_win*) * LAST)))
		exit_failure("Malloc failure\n", map);
	if (!(new = ft_lstnew(map->text)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new);
	i = 0;
	while (i < LAST)
	{
		easy_malloc((void**)&(map->text[i]), sizeof(t_win), map);
		i++;
	}
}
