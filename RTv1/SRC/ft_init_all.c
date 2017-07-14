#include "rtv1.h"

void	init_all(t_all *all)
{
	all->mlx = malloc(sizeof(t_mlx));
	all->mlx->mlx = mlx_init();
	all->mlx->wnd = mlx_new_window(all->mlx->mlx, D_WIDTH, D_HEIGHT, D_NAME);
	all->dsp.dsp_w = D_WIDTH;
	all->dsp.dsp_h = D_HEIGHT;
	all->dsp.half_h = all->dsp.dsp_h / 2;
	all->dsp.half_w = all->dsp.dsp_w / 2;
	all->dsp.rend_hs = 0 - all->dsp.half_h;
	all->dsp.rend_he = 0 + all->dsp.half_h;
	all->dsp.rend_ws = 0 - all->dsp.half_w;
	all->dsp.rend_we = 0 + all->dsp.half_w;
	all->cam = (t_vertex){0, 0, -1000};
	all->light = (t_vertex){500, 300, -1000};
	all->trans.zoom = 0;
	all->rt.brightness = 1;
	all->rt.brightness = 0;
	all->rt.rgb = (t_rgb){0, 0, 0, 0};
	all->rt.norm = (t_vertex){0, 0, 0};
}
