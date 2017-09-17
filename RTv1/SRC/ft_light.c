#include "rtv1.h"
void		ft_calc_light_init(t_all *all, int *size, t_rgb *max, t_irgb *color_int)
{
	*size = 0;
	*color_int = (t_irgb){0, 0, 0};
	*max = (t_rgb){0, 0, 0, 0};
	all->flags.shadow = 0;
}
t_rgb		ft_light_calc(t_all *all, t_rgb *color)
{
	int			size;
	t_light		*ptr;
	t_irgb		color_int;
	t_rgb		max;

	ptr = all->light;
	ft_calc_light_init(all, &size, &max, &color_int);
	while (ptr != NULL)
	{
		size++;
		all->phong = ft_phong(&all->rt, color, *ptr->o, all->cam);
		all->flags.shadow = ft_shadow_ray(all, ptr);
		if (!all->flags.shadow)
		{
			if (all->x == -87 && all->y == 197)
			{
				printf("(in)spot: %d --> red: %d green: %d blue: %d\n", size, max.r, max.g, max.b);
				printf("power : %f\n", ptr->power);
			}
			max.r = (UC)fmin(((all->phong.amb.r + all->phong.dif.r + all->phong.spc.r * all->rt.spc_int) * ptr->power), 255);
			max.g = (UC)fmin(((all->phong.amb.g + all->phong.dif.g + all->phong.spc.g * all->rt.spc_int) * ptr->power), 255);
			max.b = (UC)fmin(((all->phong.amb.b + all->phong.dif.b + all->phong.spc.b * all->rt.spc_int) * ptr->power), 255);
			max.opacity = 0;
			if (all->x == -87 && all->y == 197)
				printf("(out)spot: %d --> red: %d green: %d blue: %d\n", size, max.r, max.g, max.b);
		}
		else
		{
			max = all->phong.dif;
			max = (t_rgb) {(UC)(max.r * SHADOW),
							  (UC)(max.g * SHADOW) ,
							  (UC)(max.b * SHADOW), 0};
		}
		color_int.r += max.r;
		color_int.g += max.g;
		color_int.b += max.b;
		ptr = ptr->next;
	}
	if (size == 0)
	{
		all->phong = ft_phong(&all->rt, color, all->light_defoult, all->cam);
		return (all->phong.amb);
	}
	color_int.r = (int)fmin(255, color_int.r);
	color_int.g = (int)fmin(255, color_int.g);
	color_int.b  = (int)fmin(255, color_int.b);
	max.r = (UC)color_int.r;
	max.g = (UC)color_int.g;
	max.b = (UC)color_int.b;
	return (max);
}