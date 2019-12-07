/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:27:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/07 19:33:06 by pganglof         ###   ########.fr       */
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
# define RES_X			1920
# define RES_Y			1080

typedef struct	s_pos
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	double		perpwalldist;
	double		lineheight;
	int			drawstart;
	int			drawend;
	double		beta;
	int			av;
	int			re;
	int			ga;
	int			dr;
	int			rdr;
	int			rga;
}				t_pos;

typedef struct	s_win
{
	int			x;
	int			y;
	int			i;
	int			color;
	void		*mlx;
	void		*win;
	void		*img;
	int			b_p;
	int			size_l;
	int			endian;
}				t_win;

typedef struct	s_map
{
	int			x;
	int			y;
	double		dis_proj_plane;
	int			**map;
	int			hor;
	int			ver;
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
int		draw_wall(int key, void *param);
int		main(int argc, char **argv);
void	define_dis(t_map *map, unsigned int *str);
void	define_color(t_map *map, int side);
void	define_height(t_map *map);
void	define_diswall(t_map *map, int side, int mapx, int mapy);
int		release_key(int key, void *param);
void	move_gamer(t_map *map);

#endif