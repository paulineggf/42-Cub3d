/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:27:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/03 11:32:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

# define ALPHA			60
# define BLOCK_SIZE 	64
# define BUFFER_CUB		33
# define PROJ_PLANE_X	1920
# define PROJ_PLANE_Y	1080

typedef struct	s_pos
{
	int			posx;
	int			posy;
	double		unitx;
	double		unity;
	double		degree;
	double		beta;
	int			facing_up;
	int			facing_down;
	int			facing_right;
	int			facing_left;
	int			hor;
	int			ver;
	double		slice_height;
	double		dis;
}				t_pos;

typedef struct		s_win
{
	int		x;
	int		y;
	int		i;
	int		color;
	void	*mlx;
	void	*win;
	void	*img;
	int		b_p;
	int		size_l;
	int		endian;
}					t_win;

typedef struct	s_map
{
	int			x;
	int			y;
	double		dis_proj_plane;
	int			**map;
	t_win		*ptr;
	t_pos		*gamer;
}				t_map;

int		malloc_map(t_map *map);
int		init_map(char *av, t_map *map);
int		define_y(int fd, char *buf, t_map *map, int *ret);
int		define_x(int fd, char *buf, t_map *map, int *ret);
int		ft_close(int fd);
int		fill_map(int fd, t_map *map);
void	init_pos(t_map *map, int orientation, int x, int y);
int		launch_game(t_map *map);
t_pos	*is_wall(t_map *map);
t_pos	*free_wall(t_pos *ret, t_pos **wall);
//float	dis_wall(t_pos *gamer, t_pos *wall);
int		draw_wall(int key, void *param);
void	fill_wall_hor(t_map *map, t_pos *wall_hor);
void	fill_wall_ver(t_map *map, t_pos *wall_ver);
t_pos	*ft_closer(t_map *map, t_pos *wall_hor, t_pos *wall_ver);

#endif