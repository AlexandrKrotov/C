#include "rtv1.h"

t_objs	*ft_find_empty(t_objs *scene, t_objs *ptr)
{
	if (scene->obj == NULL)
		ptr = scene;
	else
	{
		ptr = scene;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_objs));
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (ptr);
}
///TODO "if (lst == NULL) {no-draw}
void 	ft_create_obj_lst(t_all *all)
{
/// TODO "BREAK ON CREATE PLANE"
	ft_add_plane(all->scene,(t_vertex){0, 0, 2000},
				 (t_vertex){0, 0, -1},
				 (t_rgb){255, 255, 255, 0});
	ft_add_plane(all->scene,
				 (t_vertex){0, 300, 0},
				 (t_vertex){0, -1, 0},
				 (t_rgb){100, 100, 100, 0});
	ft_add_cone(all->scene,
				(t_vertex){200, 0, 100},
				(t_vertex){0, -1, 0},
				(t_rgb){155, 155, 0}, 20);
	ft_add_cylinder(all->scene,
					(t_vertex){0, 0, 300},
					(t_vertex){1, 0, 0},
					(t_rgb){21, 64, 85, 0}, 30);
	ft_add_sphere(all->scene,
				  (t_vertex){-100, -100, 100},
				  (t_rgb){255, 0, 0, 0}, 75);
	ft_add_sphere(all->scene,
				  (t_vertex){0, 50, 100},
				  (t_rgb){0, 255, 0, 0}, 50);
	ft_add_sphere(all->scene,
				  (t_vertex){50, 50, 200},
				  (t_rgb){0, 0, 255, 200}, 50);
}