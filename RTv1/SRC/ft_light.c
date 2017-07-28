#include "rtv1.h"

t_rgb		ft_phong_ambiand(t_all *all, t_rgb *color)
{
	t_rgb ret;

	ret.r = (unsigned char)(color->r * all->rt.amb_int);
	ret.g = (unsigned char)(color->g * all->rt.amb_int);
	ret.b = (unsigned char)(color->b * all->rt.amb_int);
	return (ret);
}

t_rgb		ft_phong_diffuse(t_all *all, t_vertex l, t_rgb *color)
{
	t_rgb	ret;
	double	dif_fact;

	dif_fact = fmax(0.0, ft_dot_product(ft_reverse_vector(l), all->rt.norm));
	ret.r = (unsigned char)(dif_fact * color->r);
	ret.g = (unsigned char)(dif_fact * color->g);
	ret.b = (unsigned char)(dif_fact * color->b);
	return (ret);
}

t_rgb		ft_phong_specular(t_all *all, t_vertex l)
{
	t_vertex	r;
	t_vertex	v;
	t_rgb		ret;
	double		spc_fact;

	v = ft_sub_vector(all->rt.inter, all->cam);
	v = ft_normalized_vector(v);
	r = ft_reflect_vector(l, all->rt.norm);
	r = ft_normalized_vector(r);
	spc_fact = pow(fmax(0.0, ft_dot_product(v, r)), all->rt.n);
	ret.r = (unsigned char)(255 * spc_fact);
	ret.g = (unsigned char)(255 * spc_fact);
	ret.b = (unsigned char)(255 * spc_fact);
	ret.opacity = 0;
	return (ret);
}

t_phong		ft_phong(t_all *all, t_rgb *color, t_light *light)
{
	t_vertex	l;
	t_phong		phong;

	l = ft_sub_vector(all->rt.inter, light->o);
	l = ft_normalized_vector(l);
	phong.amb = ft_phong_ambiand(all, color);
	phong.dif = ft_phong_diffuse(all,l, color);
	phong.spc = ft_phong_specular(all, l);

	return (phong);
}

t_rgb		ft_light_calc(t_all *all, t_rgb *color)
{
	t_light	*ptr;
	int		size;
	t_irgb	ic;

	ptr = all->light;
	size = 0;
	ic = (t_irgb){0, 0, 0};
	while (ptr != NULL)
	{
		size++;
		all->flags.shadow = ft_shadow_ray(all, ptr);
		all->phong = ft_phong(all, color, ptr);
		if (!all->flags.shadow)
		{
			color->r = (UC)fmin((all->phong.dif.r + all->phong.spc.r * all->rt.spc_int), 255);
			color->g = (UC)fmin((all->phong.dif.g + all->phong.spc.g * all->rt.spc_int), 255);
			color->b = (UC)fmin((all->phong.dif.b + all->phong.spc.b * all->rt.spc_int), 255);
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
	return ((t_rgb){(UC)(ic.r / size),
					(UC)(ic.g / size),
					(UC)(ic.b / size)});
}

