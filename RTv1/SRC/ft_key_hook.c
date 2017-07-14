#include "rtv1.h"

int		ft_key_hook(int key, t_all *all)
{
	printf("key: %d\n", key);
	if (key == 53)
		ft_exit();
	if (key == 13)
		all->trans.zoom += 10;
	if (key == 1)
		all->trans.zoom -= 10;
	return (1);
}