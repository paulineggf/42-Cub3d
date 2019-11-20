#include <libc.h>
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

typedef struct		s_struct
{
	int	x;
	int	y;
	int	i;
	int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_struct;

int	deal_key(int key, void *param)
{
	while (((t_struct*)(param))->i <= 900)
	{
		while (((t_struct*)(param))->x < 1000)
		{
			mlx_pixel_put((void*)&key, ((t_struct*)(param))->win_ptr, ((t_struct*)(param))->i, ((t_struct*)(param))->x, ((t_struct*)(param))->color);
			((t_struct*)(param))->x += 1;
		}
		while (((t_struct*)(param))->y < 1000)
		{
			mlx_pixel_put((void*)&key, ((t_struct*)(param))->win_ptr, ((t_struct*)(param))->y, ((t_struct*)(param))->i, ((t_struct*)(param))->color);
			((t_struct*)(param))->y += 1;
		}
		((t_struct*)(param))->i += 100;
		((t_struct*)(param))->x = 0;
		((t_struct*)(param))->y = 0;
	}
	return (0);
}

int	main()
{
	t_struct *ptr;

	if (!ptr)
		ft_bzero((void*)ptr, sizeof(t_struct));
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 1000, 1000, "test");
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF6F8F);
	ptr->color = 0xFF6F8F;
	ptr->i = 100;
	mlx_mouse_hook(ptr->win_ptr, deal_key, (void*)ptr);
	ptr->color = 0xFFFF00;
	ptr->i = 50;
	mlx_key_hook(ptr->win_ptr, deal_key, (void*)ptr);
	mlx_loop(ptr->mlx_ptr);

}
