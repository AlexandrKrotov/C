#include "rtv1.h"

void 	ft_crete_lst(t_all *all)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cone 		*cone;
	t_objs		*ptr;

//	///BLUE SPHERE
//	all->scene = malloc(sizeof(t_objs));
//	all->scene->next = NULL;
//	sphere = malloc(sizeof(t_sphere));
//	all->scene->obj = sphere;
//	all->scene->ft_inter = ft_sphere_intersect;
//	sphere->center = (t_vertex){0, 0, 800};
//	sphere->radius = 200.0;
//	sphere->r2 = sphere->radius * sphere->radius;
//	sphere->color = (t_rgb){0, 0, 255, 0};
//	ptr = all->scene;
	///BACK PLANE
	all->scene = malloc(sizeof(t_objs));
	all->scene->next = NULL;
	plane = malloc(sizeof(t_plane));
	all->scene->obj = plane;
	all->scene->ft_inter = ft_plane_intersect;
	all->scene->ft_info = ft_get_info_plane;
	plane->ray.d = (t_vertex){0, 0 , -1};
	plane->ray.o = (t_vertex){0, 0 , 3000};
	plane->color = (t_rgb){255, 255, 255, 0};
	ptr = all->scene;
	///BLUE SPHERE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	ptr->obj = sphere;
	ptr->ft_inter = ft_sphere_intersect;
	ptr->ft_info = ft_get_info_sphere;
	sphere->center = (t_vertex){0, 0, 680};
	sphere->radius = 100.0;
	sphere->r2 = sphere->radius * sphere->radius;
	sphere->color = (t_rgb){0, 0, 255, 0};
	///GREEN SPHERE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	ptr->obj = sphere;
	ptr->ft_inter = &ft_sphere_intersect;
	ptr->ft_info = ft_get_info_sphere;
	sphere->center = (t_vertex){-185, 100, 600};
	sphere->radius = 100.0;
	sphere->r2 = sphere->radius * sphere->radius;
	sphere->color = (t_rgb){0, 255, 0, 0};
	///RED SPHERE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	sphere = malloc(sizeof(t_sphere));
	ptr->obj = sphere;
	ptr->ft_inter = ft_sphere_intersect;
	ptr->ft_info = ft_get_info_sphere;
	sphere->center = (t_vertex){200, 0, 600};
	sphere->radius = 100.0;
	sphere->r2 = sphere->radius * sphere->radius;
	sphere->color = (t_rgb){255, 0, 0, 0};
	///DOWN PLANE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	ptr->ft_info = ft_get_info_plane;
	plane->ray.d = (t_vertex){0, -1, 0};
	plane->ray.o = (t_vertex){0, 300 , 0};
	plane->color = (t_rgb){255, 255, 255, 0};
	///LEFT PLANE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	ptr->ft_info = ft_get_info_plane;
	plane->ray.d = (t_vertex){1, 0 , 0};
	plane->ray.o = (t_vertex){-600, 0 , 0};
	plane->color = (t_rgb){255, 0, 0, 0};
	///RIGHT PLANE
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	plane = malloc(sizeof(t_plane));
	ptr->obj = plane;
	ptr->ft_inter = ft_plane_intersect;
	ptr->ft_info = ft_get_info_plane;
	plane->ray.d = (t_vertex){-1, 0, 0};
	plane->ray.o = (t_vertex){600, 0 , 0};
	plane->color = (t_rgb){0, 0, 255, 0};
	///CYLINDER
	ptr->next = malloc(sizeof(t_objs));
	ptr = ptr->next;
	ptr->next = NULL;
	cylinder = malloc(sizeof(t_cylinder));
	ptr->obj = cylinder;
	ptr->ft_inter = ft_cylinder_intersect;
	ptr->ft_info = ft_get_info_cylinder;
	cylinder->ray.d = (t_vertex){1, 0, 0};
	cylinder->ray.o = (t_vertex){0, 0, 300};
	cylinder->r = 20;
	cylinder->r2 = cylinder->r * cylinder->r;
	cylinder->color = (t_rgb){41, 127, 170, 0};
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
	cone->color = (t_rgb){255, 255, 0};
}