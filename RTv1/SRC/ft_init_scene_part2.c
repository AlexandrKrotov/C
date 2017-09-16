#include "rtv1.h"

void	ft_init_scene_2(t_all *all)
{
	int red;
	int green;
	int blue;

	red = rand() % 255;
	green = rand() % 255;
	blue = rand() % 255;

	ft_add_light_lst(all->light, (t_vertex){0, 0, -1000});
	ft_add_sphere(all->scene,
				  (t_vertex){red, green, blue},
				  (t_rgb){0, 255, 0, 0}, 50);
}

void	ft_init_multilight(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){-500, 0, -1000});
	ft_add_light_lst(all->light, (t_vertex){500, 0, -1000});

	ft_add_cylinder(all->scene,
					(t_vertex){0, 0, 300},
					(t_vertex){1, 0, 0},
					(t_rgb){21, 64, 85, 0}, 30);
	ft_add_cylinder(all->scene,
					(t_vertex){0, 0, 300},
					(t_vertex){1, 0, 0},
					(t_rgb){21, 64, 85, 0}, 30);
	ft_add_cylinder(all->scene,
					(t_vertex){0, 0, 300},
					(t_vertex){1, 0, 0},
					(t_rgb){21, 64, 85, 0}, 30);
	ft_add_cylinder(all->scene,
					(t_vertex){0, 0, 300},
					(t_vertex){1, 0, 0},
					(t_rgb){21, 64, 85, 0}, 30);
}
