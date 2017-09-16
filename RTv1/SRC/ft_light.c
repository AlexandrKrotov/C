#include "rtv1.h"

t_vertex	*ft_crete_light_node(t_vertex pos)
{
	t_vertex *ptr;

	ptr = malloc(sizeof(t_vertex));
	*ptr = (t_vertex)pos;

	return (ptr);
}

void	ft_add_light_lst(t_light *light, t_vertex pos)
{
	t_light *ptr;

	if (light->o == NULL)
	{
		light->o = ft_crete_light_node(pos);
		light->next = NULL;
	}

	else
	{
		ptr = light;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_light));
		ptr = ptr->next;
		ptr->o = ft_crete_light_node(pos);
		ptr->next = NULL;
	}
}

void	ft_create_light_lst(t_all *all)
{
	//TODO "ЗАЙМИСЬ! 1 ИСТОЧНИК ЯРЧЕ ЧЕМ НЕСКОЛЬКО!"
	ft_add_light_lst(all->light, (t_vertex){-500, 0, -1000});
	ft_add_light_lst(all->light, (t_vertex){500, 0, -1000});
//	ft_add_light_lst(all->light, (t_vertex){0, 0, -1000});
}

t_rgb		ft_light_calc(t_all *all, t_rgb *color)
{
	t_light		*ptr;
	int			size;
	t_irgb		color_int;
	t_rgb		max;
	t_vertex	l;

	ptr = all->light;
	size = 0;
	color_int = (t_irgb){0, 0, 0};
	max = (t_rgb){0, 0, 0, 0};
	while (ptr != NULL)
	{
		////TODO "FRICK CONSTRUCTION"
//		l = ft_sub_vector(all->rt.inter, *ptr->o);
//		if (ft_cos_vector(all->rt.norm, l) > 0)
//		{
//			ptr = ptr->next;
//			continue ;
//		}
		size++;
		all->phong = ft_phong(&all->rt, color, *ptr->o, all->cam);
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
		color_int.r += color->r;
		color_int.g += color->g;
		color_int.b += color->b;
		ptr = ptr->next;
	}
	if (size == 0)
	{
		all->phong = ft_phong(&all->rt, color, all->light_defoult, all->cam);
		return (all->phong.amb);
	}
	color_int.r /= size;
	color_int.g /= size;
	color_int.b /= size;
	max.r = (UC)color_int.r;
	max.g = (UC)color_int.g;
	max.b = (UC)color_int.b;
	return (max);
}