#include "rtv1.h"

t_light		*ft_crete_light_node(t_vertex pos)
{
	t_light *ptr;

	ptr = malloc(sizeof(t_light));
	ptr->o = (t_vertex)pos;
	ptr->next = NULL;

	return (ptr);
}

t_light		*ft_add_light_lst(t_light *light, t_vertex pos)
{
	t_light *ptr;

	if (light == NULL)
		light = ft_crete_light_node(pos);
	else
	{
		ptr = light;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_crete_light_node(pos);
	}
	return (light);
}

void	ft_create_light_lst(t_all *all)
{
	//TODO "ЗАЙМИСЬ! 1 ИСТОЧНИК ЯРЧЕ ЧЕМ НЕСКОЛЬКО!"
	all->light = ft_add_light_lst(all->light, (t_vertex){-500, 0, -1000});
	all->light = ft_add_light_lst(all->light, (t_vertex){500, 0, -1000});
	all->light = ft_add_light_lst(all->light, (t_vertex){0, 0, -1000});
}

t_rgb		ft_light_calc(t_all *all, t_rgb *color)
{
	t_light		*ptr;
	t_irgb		color_int;
	t_rgb		max;
	int			size;

	ptr = all->light;
	size = 0;
	color_int = (t_irgb){0, 0, 0};
	max = (t_rgb){0, 0, 0, 0};
	while (ptr != NULL)
	{
		size++;
		all->phong = ft_phong(&all->rt, color, ptr, all->cam);
//		all->flags.shadow = ft_shadow_ray(all, ptr);
		if (!all->flags.shadow)
		{
			color->r = (UC)fmin((all->phong.amb.r + all->phong.dif.r + all->phong.spc.r * all->rt.spc_int), 255);
			color->g = (UC)fmin((all->phong.amb.g + all->phong.dif.g + all->phong.spc.g * all->rt.spc_int), 255);
			color->b = (UC)fmin((all->phong.amb.b + all->phong.dif.b + all->phong.spc.b * all->rt.spc_int), 255);
			color->opacity = 0;
		}
		else
		{
			*color = all->phong.dif;
			*color = (t_rgb) {(UC)(color->r * SHADOW),
							  (UC)(color->g * SHADOW),
							  (UC)(color->b * SHADOW), 0};
		}
//		max.r = (max.r > color->r ? max.r : color->r);
//		max.g = (max.g > color->g ? max.g : color->g);
//		max.b = (max.b > color->b ? max.b : color->b);
		color_int.r += color->r;
		color_int.g += color->g;
		color_int.b += color->b;
		ptr = ptr->next;
	}
	if (size == 0)
	{
		all->phong = ft_phong(&all->rt, color, ptr, all->cam);
		return (all->phong.amb);
	}
	color_int.r /= size;
	color_int.g /= size;
	color_int.b /= size;
//	max.r = (UC)(max.r > color_int.r ? max.r : color_int.r);
//	max.g = (UC)(max.g > color_int.g ? max.g : color_int.g);
//	max.b = (UC)(max.b > color_int.b ? max.b : color_int.b);
	max.r = (UC)color_int.r;
	max.g = (UC)color_int.g;
	max.b = (UC)color_int.b;
	return (max);
}