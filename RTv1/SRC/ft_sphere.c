#include "rtv1.h"

int		ft_sphere_shadowray(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_sphere	*s;
	t_vertex	o;
	t_vertex	d;
	t_vertex	oc;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	s = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, s->center);
	b = 2 * ft_dot_product(oc, d);
	c = ft_dot_product(oc, oc) - s->r2;
	disc = b * b - 4 * c;
	if (disc < 0)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / 2;
	t1 = (-b + disc) / 2;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6)
		return(TRUE);
	return(FALSE);
}

int		ft_sphere_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_sphere	*s;
	t_vertex	o;
	t_vertex	d;
	t_vertex	temp;
	t_vertex	oc;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	s = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, s->center);
	b = 2 * ft_dot_product(oc, d);
	c = ft_dot_product(oc, oc) - s->r2;
	disc = b * b - 4 * c;
	if (disc < 0)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / 2;
	t1 = (-b + disc) / 2;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6 && t0 < all->rt.t)
	{
		all->rt.t = t0;
		all->rt.rgb = s->color;
		temp = ft_mult_vec_double(d, all->rt.t);
		all->rt.inter = ft_sum_vector(o, temp);
		all->rt.norm = ft_sub_vector(all->rt.inter, s->center);
		all->rt.norm = ft_devide_vec_double(all->rt.norm, s->radius);
		return(TRUE);
	}
	return(FALSE);
}