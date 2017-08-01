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
	{
		light = ft_crete_light_node(pos);
		return (light);
	}
	ptr = light;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = ft_crete_light_node(pos);
	return (light);
}

void	ft_create_light_lst(t_all *all)
{
	///ЗАЙМИСЬ! 1 ИСТОЧНИК ЯРЧЕ ЧЕМ НЕСКОЛЬКО!
	all->light = ft_add_light_lst(all->light, (t_vertex){-1000, 0, 0});
//	all->light = ft_add_light_lst(all->light, (t_vertex){-1000, 0, -1000});
	all->light = ft_add_light_lst(all->light, (t_vertex){0, 0, -1000});
}

t_rgb		ft_light_calc(t_all *all, t_rgb *color)
{
	t_light		*ptr;
	t_irgb		ic;
//	t_phong		phong;
	int			size;

	ptr = all->light;
	size = 0;
	ic = (t_irgb){0, 0, 0};
	while (ptr != NULL)
	{
		size++;
		all->phong = ft_phong(&all->rt, color, ptr, all->cam);
		all->flags.shadow = ft_shadow_ray(all, ptr);
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
//		*color = all->phong.dif;
		ic.r += color->r;
		ic.g += color->g;
		ic.b += color->b;
		ptr = ptr->next;
	}
	if (size == 0)
	{
		all->phong = ft_phong(&all->rt, color, ptr, all->cam);
		return (all->phong.amb);
	}
	return ((t_rgb){(UC)(ic.r / size),
					(UC)(ic.g / size),
					(UC)(ic.b / size)});
}