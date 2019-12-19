/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:03:43 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 17:19:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_realloc(char *str, char *buf, int n)
{
	char	*new;

	if (!(new = malloc(n)))
		return (NULL);
	ft_strcpy(new, str);
	ft_strcat(new, buf);
	new[n] = '\0';
	free(str);
	return (new);
}
