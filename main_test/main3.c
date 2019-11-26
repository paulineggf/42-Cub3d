#include <libc.h>
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

typedef struct		s_struct
{
	int		width;
	int		height;
	int		color;
	int		x;
	int		y;
	int		tmpy;
	int		tmpx;
	void	*mlx_ptr;
	void	*win_ptr;
}					t_struct;

void	background(int key, t_struct *p)
{
	p->tmpy = p->y;
	p->tmpx = p->x;
	while (p->y <= 200)
	{
		while (p->x <= 320)
			mlx_pixel_put(&key, p->win_ptr, p->x++, p->y, 0xFFFFFF);
		p->x = p->tmpx;
		p->y++;
	}
	p->x = p->tmpx;
	p->y = p->tmpy;
}

void	wall(int key, t_struct *p)
{
	p->x += 1;
	p->y += 1;
	p->tmpy = p->y;
	p->tmpx = p->x;
	while (p->y <= p->height)
	{
		while (p->x <= p->width)
			mlx_pixel_put(&key, p->win_ptr, p->x++, p->y, 0xFFA45A);
		p->x = p->tmpx;
		p->y++;
	}
	p->x = p->tmpx;
	p->y = p->tmpy;
	p->height -= 1;
	p->width -= 1;
}

void	backoff(int key, t_struct *p)
{
	background(key, p);
	wall(key, p);
}

void	forward(int key, t_struct *p)
{
	while (p->y <= p->height)
	{
		while (p->x <= p->width)
			mlx_pixel_put(&key, p->win_ptr, p->x++, p->y, 0xFFA45A);
		p->x = 0;
		p->y++;
	}
	p->y = 0;
}

int		deal_key(int key, void *param)
{
	t_struct	*p;

	p = (t_struct*)param;
	if (key == 6)
		backoff(key, p);
	if (key == 12)
		forward(key, p);
	return (1);
}

t_struct	*init_struct_window(void)
{
	t_struct *ptr;

	ptr = NULL;
	if (!(ptr = malloc(sizeof(t_struct))))
		return (NULL);
	ft_bzero(ptr, sizeof(t_struct));
	ptr->mlx_ptr = mlx_init();
	ptr->width = 320;
	ptr->height = 200;
	ptr->x = 0;
	ptr->y = 0;
	ptr->color = 0xFAF48F;
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->width, ptr->height, "TEST");
	return (ptr);
}

int		main(void)
{
	t_struct *ptr;

	if (!(ptr = init_struct_window()))
		return (0);
	mlx_key_hook(ptr->win_ptr, deal_key, ptr);
	mlx_loop(ptr->mlx_ptr);
}
