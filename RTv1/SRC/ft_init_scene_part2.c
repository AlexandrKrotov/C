#include "rtv1.h"

void	ft_init_scene_2(t_all *all)
{
	t_rgb		color;
	t_vertex	pos;
	int			size;

	ft_add_light_lst(all->light, (t_vertex){-500, -500, -500}, 0.5);
	ft_add_random_sphere(all);
	ft_random_value(&pos, &color, &size);
	ft_add_cylinder(all->scene,
					(t_vertex){pos.x, pos.y, pos.z},
					(t_vertex){0, 1, 0},
					(t_rgb){color.r, color.g, color.b, 0}, size);
	ft_random_value(&pos, &color, &size);
	ft_add_cylinder(all->scene,
					(t_vertex){pos.x, pos.y, pos.z},
					(t_vertex){1, 0, 0},
					(t_rgb){color.r, color.g, color.b, 0}, size);
	ft_random_value(&pos, &color, &size);
	ft_add_cylinder(all->scene,
					(t_vertex){pos.x, pos.y, pos.z},
					(t_vertex){0, 1, 0},
					(t_rgb){color.r, color.g, color.b, 0}, size);
}

void	ft_add_plane_ml(t_all *all)
{
	ft_add_plane(all->scene,
				 (t_vertex){0, 0, 2000},
				 (t_vertex){0, 0, -1},
				 (t_rgb){255, 255, 255, 0});
	ft_add_plane(all->scene,
				 (t_vertex){0, 300, 0},
				 (t_vertex){0, -1, 0},
				 (t_rgb){255, 255, 255, 0});
	ft_add_plane(all->scene,
				 (t_vertex){0, -300, 0},
				 (t_vertex){0, 1, 0},
				 (t_rgb){255, 255, 255, 0});
}

void	ft_add_sphere_ml(t_all *all)
{
	ft_add_sphere(all->scene,
				  (t_vertex){-200, 350, 50},
				  (t_rgb){150, 150, 150, 0}, 100);
	ft_add_sphere(all->scene,
				  (t_vertex){200, 350, 50},
				  (t_rgb){150, 150, 150, 0}, 100);
	ft_add_sphere(all->scene,
				  (t_vertex){-200, 350, 900},
				  (t_rgb){150, 150, 150, 0}, 100);
	ft_add_sphere(all->scene,
				  (t_vertex){200, 350, 900},
				  (t_rgb){150, 150, 150, 0}, 100);
}

void	ft_add_cylinder_ml(t_all *all)
{
	ft_add_cylinder(all->scene,
					(t_vertex){-200, 0, 900},
					(t_vertex){0, 1, 0},
					(t_rgb){150, 150, 150, 0}, 30);
	ft_add_cylinder(all->scene,
					(t_vertex){200, 0, 900},
					(t_vertex){0, 1, 0},
					(t_rgb){150, 150, 150, 0}, 30);
	ft_add_cylinder(all->scene,
					(t_vertex){200, 0, 50},
					(t_vertex){0, 1, 0},
					(t_rgb){150, 150, 150, 0}, 30);
	ft_add_cylinder(all->scene,
					(t_vertex){-200, 0, 50},
					(t_vertex){0, 1, 0},
					(t_rgb){150, 150, 150, 0}, 30);
}

void	ft_init_multilight(t_all *all)
{
	ft_add_light_lst(all->light, (t_vertex){600, 0, -500}, 0.5);
	ft_add_light_lst(all->light, (t_vertex){-600, 0, -500}, 0.5);
	ft_add_plane_ml(all);
	ft_add_cylinder_ml(all);
	ft_add_sphere_ml(all);
}
