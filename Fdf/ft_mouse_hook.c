#include "FdF.h"


int	ft_mouse_cord( int x,int y, t_all *all)
{
	if(all->animation == 1)
	{
		if (x > D_WIDTH)
			all->trans.shift.x_shift -= 2;
		if (x < 0)
			all->trans.shift.x_shift += 2;
		if (y > D_HEIGHT)
			all->trans.shift.y_shift -= 2;
		if (y < 0)
			all->trans.shift.y_shift += 2;
		create_img(all);
		mlx_hook(all->mlx->wnd, 6, (1L << 6), ft_mouse_cord, all);
	}
	return (0);
}

int	ft_mouse_hook(int button, int x,int y, t_all *all)
{
	printf ("x: %u\n" , x);
	printf ("y: %u\n" , y);
	printf("%d\n", button);
	if (button == 4)
		if(all->trans.scale != 0)
		{
			all->trans.scale += 0.01;
			if (all->trans.scale <= 0)
				all->trans.scale = 0.01;
		}
	if (button == 5)
	{
		all->trans.scale -= 0.01;
		if (all->trans.scale <= 0)
			all->trans.scale = 0.001;
	}
	if (button == 1)
	{
		if (all->animation == 0)
			all->animation = 1;
		else
			all->animation = 0;
	}
	create_img(all);
	return (0);
}
