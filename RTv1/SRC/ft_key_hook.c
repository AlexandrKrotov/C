#include "rtv1.h"

int		ft_key_hook(int key, t_all *all)
{
	printf("key: %d\n", key);
	if (key == ESC)
		ft_exit();
	if (key == K_UP || key == W)
		all->trans.zoom += 100;
	if (key == K_DOWN || key == S)
		all->trans.zoom -= 100;
	if (key == K_LEFT || key == A)
		all->trans.shift -= 50;
	if (key == K_RIGHT || key == D)
		all->trans.shift += 50;
	all->flags.redraw = TRUE;
	if (key == A)
		all->flags.aliasing = all->flags.aliasing == FALSE ? TRUE : FALSE;
	return (1);
}