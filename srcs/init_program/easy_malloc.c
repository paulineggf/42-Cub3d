/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:35:14 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/06 17:22:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	easy_malloc(void **content, size_t n, t_map *map)
{
	t_list	*new;

	if (!(*content = malloc(n)))
		exit_failure("Malloc failure\n", map);
	ft_bzero(*content, n);
	if (!(new = ft_lstnew(*content)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new);
}
