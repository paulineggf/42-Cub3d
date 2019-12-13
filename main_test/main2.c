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
	void	*img_ptr;
}			t_struct;

int		new_img(int key, void *param)
{
	char	*str;
/*	int		test = 456;
	int		test2 = 155;
	int		test3 = 1;
	unsigned char	color[4];*/
	int		c;
	t_struct	*p;

	int i = 0;
	c = 0x458745;
	int x = 0;
	p = (t_struct*)param;
	int b_p;
	int size_l;
	int endian;
	p->img_ptr = mlx_new_image(p->mlx_ptr, 1000, 1000);
	str = mlx_get_data_addr(p->img_ptr, &b_p, &size_l, &endian);
	printf("b_p %d\nsize_l : %d\n", b_p, size_l);
	while (i < 1000)
	{
		x = 0;
		while (x < size_l)
		{
			ft_memcpy(str + ((size_l * i) + x), &c, 4);
			x += 4;
		}
		i++;
	}
	printf("x : %d\n", x);
	mlx_put_image_to_window(p->mlx_ptr, (void*)&key, p->img_ptr, 0, 0);
	return (1);
}

int		main()
{
	t_struct *ptr;

	ptr = malloc(sizeof(t_struct));
		ft_bzero((void*)ptr, sizeof(t_struct));
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "test");
	mlx_key_hook(ptr.win_ptr, new_img, ptr);
	mlx_loop(ptr.mlx_ptr);
}
