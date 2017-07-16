#include "rtv1.h"

void 	ft_crete_lst(t_all *all)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_objs		*ptr;

	all->scene = malloc(sizeof(t_objs));
	all->scene->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	all->scene->obj = sphere;
	all->scene->ft_inter = &ft_sphere_intersect;
	sphere->center = (t_vertex){0, 0, 200};
	sphere->radius = 200.0;
	sphere->color = (t_rgb){0, 0, 255, 0};
	ptr = all->scene;
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	ptr->obj = sphere;
	ptr->ft_inter = &ft_sphere_intersect;
	sphere->center = (t_vertex){-300, 0, 500};
	sphere->radius = 100.0;
	sphere->color = (t_rgb){0, 255, 0, 0};

	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	ptr->obj = sphere;
	ptr->ft_inter = &ft_sphere_intersect;
	sphere->center = (t_vertex){200, -100, 100};
	sphere->radius = 100.0;
	sphere->color = (t_rgb){255, 0, 0, 0};

	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	plane->point = (t_vertex){0, -500, 0};
	plane->norm = (t_vertex){0, -1, 0};
	plane->d = 500;
	plane->color = (t_rgb){255, 255, 255, 0};

	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	plane->point = (t_vertex){-500, 0, 0};
	plane->norm = (t_vertex){1, 0 , 0};
	plane->d = 500;
	plane->color = (t_rgb){255, 255, 255, 0};

	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	plane->point = (t_vertex){5000, 0, 0};
	plane->norm = (t_vertex){-1, 0 , 0};
	plane->d = 500;
	plane->color = (t_rgb){255, 255, 255, 0};

	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	plane->point = (t_vertex){0, 0, 1000};
	plane->norm = (t_vertex){0, 0 , -1};
	plane->d = 1000;
	plane->color = (t_rgb){255, 255, 255, 0};
}

