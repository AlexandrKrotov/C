#include "rtv1.h"

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