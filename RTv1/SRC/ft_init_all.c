#include "rtv1.h"

void	init_all(t_all *all)
{
	all->mlx = malloc(sizeof(t_mlx));
	all->mlx->mlx = mlx_init();
	all->mlx->wnd = mlx_new_window(all->mlx->mlx, D_WIDTH, D_HEIGHT, D_NAME);
	all->dsp.dsp_w = D_WIDTH;
	all->dsp.dsp_h = D_HEIGHT;
	all->scene = malloc(sizeof(t_objs));
	all->scene->next = NULL;
}
