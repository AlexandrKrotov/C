#include "rtv1.h"

int		ft_key_hook(int key, t_all *all)
{
	printf("key: %d\n", key);
	if (key == ESC)
		ft_exit();
//	if (key == W)
//		all->light.o.y -= 20;
//	if (key == S)
//		all->light.o.y += 20;
//	if (key == A)
//		all->light.o.x -= 20;
//	if (key == D)
//		all->light.o.x += 20;
//	if (key == Z)
//		all->light.o.z += 20;
//	if (key == X)
//		all->light.o.z -= 20;
//	printf("light.x: %f\n", all->light.o.x);
//	printf("light.y: %f\n", all->light.o.y);
//	printf("light.z: %f\n", all->light.o.z);
	if (key == K_UP)
		all->trans.zoom += 100;
	if (key == K_DOWN)
		all->trans.zoom -= 100;
	if (key == K_LEFT)
		all->trans.shift -= 50;
	if (key == K_RIGHT)
		all->trans.shift += 50;
	all->flags.redraw = TRUE;
	return (1);
}