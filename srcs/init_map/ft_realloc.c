/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:03:43 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:13:12 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_realloc(char *tmp, char *str, int n)
{
	char	*new;

	if (!(new = malloc(n)))
		return (NULL);
	ft_strcpy(new, tmp);
	ft_strcat(new, str);
	new[n - 1] = '\0';
	free(tmp);
	return (new);
}
