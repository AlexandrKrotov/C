#include "rtv1.h"

t_sphere	*ft_init_sphere(t_vertex ray_o, t_rgb color, double radius)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->center = ray_o;
	sphere->color = color;
	sphere->radius = radius;
	sphere->r2 = sphere->radius * sphere->radius;
	sphere->n = 10;
	sphere->amb_int = 0.1;
	sphere->dif_int = 1;
	sphere->spc_int = .5;

	return (sphere);
}

void	ft_add_sphere(t_objs *scene, t_vertex ray_o, t_rgb color, double radius)
{
	t_objs		*ptr;

	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_sphere(ray_o,color, radius);
	ptr->ft_inter = ft_sphere_intersect;
	ptr->ft_info = ft_get_info_sphere;
}

void	ft_get_norm_sphere(t_all *all, t_objs *ptr)
{
	t_sphere	*s;

	s = ptr->obj;
	all->rt.norm = ft_sub_vector(all->rt.inter, s->center);
	all->rt.norm = ft_divide_vec_double(all->rt.norm, s->radius);
}

void	ft_get_info_sphere(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_sphere	*s;
	t_vertex	tmp;

	s = ptr->obj;
	tmp = ft_mult_vec_double(ray->d, all->rt.t);
	all->rt.inter = ft_sum_vector(ray->o, tmp);
	ft_get_norm_sphere(all, ptr);
	all->rt.rgb = s->color;
	all->rt.n = s->n;
	all->rt.amb_int = s->amb_int;
	all->rt.dif_int = s->dif_int;
	all->rt.spc_int = s->spc_int;
}

int		ft_sphere_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_sphere	*s;
	t_vertex	oc;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	s = ptr->obj;
	oc = ft_sub_vector(ray->o, s->center);
	b = 2 * ft_dot_product(oc, ray->d);
	c = ft_dot_product(oc, oc) - s->r2;
	disc = b * b - 4 * c;
	if (disc < 1e-6)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / 2;
	t1 = (-b + disc) / 2;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6 && t0 < all->rt.t)
	{
		all->rt.t = t0;
		return(TRUE);
	}
	return(FALSE);
}