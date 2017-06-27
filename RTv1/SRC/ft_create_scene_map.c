#include "rtv1.h"

void 	ft_crete_lst(t_all *all)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	all->scene->obj = sphere;
	sphere->center = (t_vertex){all->dsp.dsp_w / 2, all->dsp.dsp_h / 2, 50};
	sphere->radius = 200.0;
	sphere->color = (t_rgb){255, 0, 0, 0};
	all->scene->next = NULL;
}

