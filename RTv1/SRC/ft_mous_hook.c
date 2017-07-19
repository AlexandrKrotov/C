#include "rtv1.h"

int 	ft_mouse_cord(int x, int y, t_all *all)
{

}

int 	ft_mouse_hook(int key, int x, int y, t_all *all)
{
	printf("key: %d\n", key);
	printf("x: %d\ny: %d\n", x - all->dsp.half_w, y - all->dsp.half_h);
	if (key == 5 && all->trans.zoom >= 0)
		all->trans.zoom += 10;
	if (key == 4 && all->trans.zoom >= 0)
		all->trans.zoom -= 10;
}
