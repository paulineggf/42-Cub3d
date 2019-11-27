/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:27:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 11:43:23 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ALPHA			60
# define BLOCK_SIZE 	64
# define BUFFER_CUB		33

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
//# include "mlx.h"

typedef struct	s_map
{
	int			x;
	int			y;
	int			**map;
}				t_map;

typedef struct	s_pos
{
	int			posx;
	int			posy;
	int			unitx;
	int			unity;
	int			degree;
}				t_pos;

int		malloc_map(t_map *map);
int		init_map(char *av, t_map *map, t_pos *gamer);
int		define_y(int fd, char *buf, t_map *map, int *ret);
int		define_x(int fd, char *buf, t_map *map, int *ret);
int		ft_close(int fd);
int		fill_map(int fd, t_map *map, t_pos *gamer);
void	init_pos(t_pos *gamer, int orientation, int x, int y);


#endif