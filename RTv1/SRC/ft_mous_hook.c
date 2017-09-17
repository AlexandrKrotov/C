#include "rtv1.h"

int 	ft_mouse_cord(int x, int y, t_all *all)
{
	return (1);
}

int 	ft_mouse_hook(int key, int x, int y, t_all *all)
{
	if (key == 5)
		all->trans.zoom += 100;
	if (key == 4)
		all->trans.zoom -= 100;
	all->flags.redraw = TRUE;
	return (1);
}
