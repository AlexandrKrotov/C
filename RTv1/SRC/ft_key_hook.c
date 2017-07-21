#include "rtv1.h"

int		ft_key_hook(int key, t_all *all)
{
	printf("key: %d\n", key);
	if (key == ESC)
		ft_exit();
	if (key == W)
		all->light.y -= 20;
	if (key == S)
		all->light.y += 20;
	if (key == A)
		all->light.x -= 20;
	if (key == D)
		all->light.x += 20;
	if (key == Z)
		all->light.z += 20;
	if (key == X)
		all->light.z -= 20;
	printf("light.x: %f\n", all->light.x);
	printf("light.y: %f\n", all->light.y);
	printf("light.z: %f\n", all->light.z);
	if (key == UP)
		all->trans.zoom += 100;
	if (key == DOWN)
		all->trans.zoom -= 100;
	return (1);
}