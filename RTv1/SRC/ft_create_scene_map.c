#include "rtv1.h"
t_plane	*ft_init_plane(t_vertex ray_o, t_vertex ray_d, t_rgb color)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	plane->ray.d = ray_d;
	plane->ray.o = ray_o;
	plane->color = color;
	plane->n = 1;
	plane->amb_int = 0.1;
	plane->dif_int = 0.6;
	plane->spc_int = 1;

	return (plane);
}

t_objs	*ft_add_plane(t_objs *scene, t_vertex ray_o, t_vertex ray_d, t_rgb color)
{
	t_objs		*ptr;

	if (scene == NULL)
	{
		scene = malloc(sizeof(t_objs));
		ptr = scene;
	}
	else
	{
		ptr = scene;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_objs));
		ptr = ptr->next;
	}
	ptr->obj = ft_init_plane(ray_o, ray_d, color);
	ptr->ft_inter = ft_plane_intersect;
	ptr->ft_info = ft_get_info_plane;
	ptr->next = NULL;
	return (scene);
}

void 	ft_create_obj_lst(t_all *all)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cone 		*cone;
	t_objs		*ptr;
/// TODO "BREAK ON CREATE PLANE"
	all->scene = ft_add_plane(all->scene,(t_vertex){0, 0 , 2000},
							 			 (t_vertex){0, 0 , -1},
							 			 (t_rgb){100, 100, 100, 0});
	ptr = all->scene;

//	all->scene = malloc(sizeof(t_objs));
//	all->scene->next = NULL;
//	sphere = malloc(sizeof(t_sphere));
//	all->scene->obj = sphere;
//	all->scene->ft_inter = ft_sphere_intersect;
//	all->scene->ft_info = ft_get_info_sphere;
//	sphere->center = (t_vertex){0, -50, 0};
//	sphere->radius = 100.0;
//	sphere->r2 = sphere->radius * sphere->radius;
//	sphere->color = (t_rgb){255, 0, 0, 0};
//	sphere->n = 10;
//	sphere->amb_int = 0.1;
//	sphere->dif_int = 1;
//	sphere->spc_int = .5;
//	ptr = all->scene;
//	///BLUE SPHERE
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	sphere = malloc(sizeof(t_sphere));
//	ptr->obj = sphere;
//	ptr->ft_inter = ft_sphere_intersect;
//	ptr->ft_info = ft_get_info_sphere;
//	sphere->center = (t_vertex){0, -200, 680};
//	sphere->radius = 100.0;
//	sphere->r2 = sphere->radius * sphere->radius;
//	sphere->color = (t_rgb){0, 0, 255, 0};
//	sphere->n = 50;
//	sphere->amb_int = 0.1;
//	sphere->dif_int = 1;
//	sphere->spc_int = .5;
//	///GREEN SPHERE
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	sphere = malloc(sizeof(t_sphere));
//	ptr->obj = sphere;
//	ptr->ft_inter = ft_sphere_intersect;
//	ptr->ft_info =  ft_get_info_sphere;
//	sphere->center = (t_vertex){0, 0, 0};
//	sphere->radius = 100.0;
//	sphere->r2 = sphere->radius * sphere->radius;
//	sphere->color = (t_rgb){255, 0, 0, 0};
//	sphere->n = 50;
//	sphere->amb_int = 0.1;
//	sphere->dif_int = 1;
//	sphere->spc_int = 1.1;
//	///RED SPHERE
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	sphere = malloc(sizeof(t_sphere));
//	ptr->obj = sphere;
//	ptr->ft_inter = ft_sphere_intersect;
//	ptr->ft_info = ft_get_info_sphere;
//	sphere->center = (t_vertex){0, 0, 0};
//	sphere->radius = 100.0;
//	sphere->r2 = sphere->radius * sphere->radius;
//	sphere->color = (t_rgb){255, 0, 0, 0};
//	sphere->n = 30;
//	sphere->amb_int = 0.1;
//	sphere->dif_int = 1;
//	sphere->spc_int = 1;
//	///DOWN PLANE
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	plane = malloc(sizeof(t_plane));
//	ptr->obj = plane;
//	ptr->ft_inter = ft_plane_intersect;
//	ptr->ft_info = ft_get_info_plane;
//	plane->ray.d = (t_vertex){0, -1, 0};
//	plane->ray.o = (t_vertex){0, 300 , 0};
//	plane->color = (t_rgb){255, 255, 255, 0};
//	plane->n = 5;
//	plane->amb_int = 0.1;
//	plane->dif_int = 0.6;
//	plane->spc_int = 1;
	///LEFT PLANE
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	plane = malloc(sizeof(t_plane));
//	ptr->obj = plane;
//	ptr->ft_inter = ft_plane_intersect;
//	ptr->ft_info = ft_get_info_plane;
//	plane->ray.d = (t_vertex){1, 0 , 0};
//	plane->ray.o = (t_vertex){-600, 0 , 0};
//	plane->color = (t_rgb){255, 0, 0, 0};
//	plane->n = 1;
//	plane->amb_int = 0.1;
//	plane->dif_int = 0.6;
//	plane->spc_int = 1;
	///RIGHT PLANE
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	plane = malloc(sizeof(t_plane));
//	ptr->obj = plane;
//	ptr->ft_inter = ft_plane_intersect;
//	ptr->ft_info = ft_get_info_plane;
//	plane->ray.d = (t_vertex){-1, 0, 0};
//	plane->ray.o = (t_vertex){600, 0 , 0};
//	plane->color = (t_rgb){0, 0, 255, 0};
//	plane->n = 1;
//	plane->amb_int = 0.1;
//	plane->dif_int = 0.6;
//	plane->spc_int = 1;
	///CYLINDER
//	ptr->next = malloc(sizeof(t_objs));
//	ptr = ptr->next;
//	ptr->next = NULL;
//	cylinder = malloc(sizeof(t_cylinder));
//	ptr->obj = cylinder;
//	ptr->ft_inter = ft_cylinder_intersect;
//	ptr->ft_info = ft_get_info_cylinder;
//	cylinder->ray.d = (t_vertex){0, 0.7, 0.7};
//	cylinder->ray.o = (t_vertex){0, 0, 300};
//	cylinder->r = 30;
//	cylinder->r2 = cylinder->r * cylinder->r;
//	cylinder->color = (t_rgb){21, 64, 85, 0};
// 	cylinder->n = 30;
//	cylinder->amb_int = 0.1;
//	cylinder->dif_int = 1;
//	cylinder->spc_int = 1;
	///CONE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	cone = malloc(sizeof(t_cone));
	ptr->obj = cone;
	ptr->ft_inter = ft_cone_intersect;
	ptr->ft_info = ft_get_info_cone;
	cone->ray.o = (t_vertex){200, 0, 100};
	cone->ray.d = (t_vertex){0, -1, 0};
	cone->alpha = 20;
	cone->rad = cone->alpha * M_PI / 180;
	cone->cos2 = cos(cone->rad) * cos(cone->rad);
	cone->sin2 = sin(cone->rad) * sin(cone->rad);
	cone->color = (t_rgb){155, 155, 0};
	cone->n = 20;
	cone->amb_int = 0.1;
	cone->dif_int = 1;
	cone->spc_int = 1;
}