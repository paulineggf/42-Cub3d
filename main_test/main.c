#include <libc.h>
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

typedef struct		s_struct
{
	int		x;
	int		y;
	int		i;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_struct;

int	deal_key(int key, void *param)
{
	t_struct *p;

	p = (t_struct*)param;
	while (p->i <= 900)
	{
		while (p->x < 1000)
		{
			mlx_pixel_put((void*)&key, p->win_ptr, p->i, p->x, p->color);
			p->x += 1;
		}
		while (p->y < 1000)
		{
			mlx_pixel_put((void*)&key, p->win_ptr, p->y, p->i, p->color);
			p->y += 1;
		}
		p->i += 100;
		p->x = 0;
		p->y = 0;
	}
	return (0);
}

int	main()
{
	t_struct *ptr;

	ptr = NULL;
	if (!ptr)
		ft_bzero((void*)ptr, sizeof(t_struct));
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 1000, 1000, "test");
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF6F8F);
	ptr->color = 0xFF6F8F;
	ptr->i = 100;
	mlx_mouse_hook(ptr->win_ptr, deal_key, (void*)ptr);
	//mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 100, 100, 0xFF10AB, "HELLO WORLD !");
	//ptr->color = 0xFFFF00;
	//ptr->i = 100;
	//mlx_key_hook(ptr->win_ptr, deal_key, (void*)ptr);
	mlx_loop(ptr->mlx_ptr);
}
