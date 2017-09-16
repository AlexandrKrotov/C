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


void 	ft_create_obj_lst(t_all *all)
{
	ft_add_sphere(all->scene,
				  (t_vertex){-100, -100, 100},
				  (t_rgb){255, 0, 0, 0}, 75);
}