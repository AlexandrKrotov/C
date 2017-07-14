#include "rtv1.h"

void 	ft_crete_lst(t_all *all)
{
	t_sphere	*sphere;
	t_sphere	*sphere2;

	all->scene = malloc(sizeof(t_objs));
	all->scene->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	all->scene->obj = sphere;
	sphere->center = (t_vertex){0, 0, 200};
	sphere->radius = 200.0;
	sphere->color = (t_rgb){0, 0, 255, 0};

	all->scene->next = malloc(sizeof(t_objs));
	all->scene->next->next = NULL;
	sphere2 = malloc(sizeof(t_sphere));
	all->scene->next->obj = sphere2;
	sphere2->center = (t_vertex){-300, 0, 500};
	sphere2->radius = 100.0;
	sphere2->color = (t_rgb){0, 255, 0, 0};

	all->scene->next->next = malloc(sizeof(t_objs));
	all->scene->next->next->next = NULL;
	sphere2 = malloc(sizeof(t_sphere));
	all->scene->next->next->obj = sphere2;
	sphere2->center = (t_vertex){200, -100, 100};
	sphere2->radius = 100.0;
	sphere2->color = (t_rgb){255, 0, 0, 0};
}

