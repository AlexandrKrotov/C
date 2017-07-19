#include "rtv1.h"

void	ft_get_normal_cylinder(t_all *all, t_cylinder *cylinder)
{
	t_vertex a;
	t_vertex gip;
	t_vertex bn;

	gip = ft_sub_vector(all->rt.inter, cylinder->center);
	a = ft_mult_vec_double(cylinder->norm, ft_dot_product(gip, cylinder->norm));
	bn = ft_sub_vector(gip, a);
	all->rt.norm = ft_normalized_vector(bn);
}

int		ft_cylinder_shadowray(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cylinder	*cyl;
	t_vertex	o;
	t_vertex	d;
	t_vertex	oc;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	cyl = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, cyl->center);
	a = d.x * d.x + d.z * d.z;
	b = (2 * d.x * (oc.x)) + (2 * d.z * (oc.z));
	c = (oc.x * oc.x) + (oc.z * oc.z) - cyl->r * cyl->r;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / 2 * a;
	t1 = (-b + disc) / 2 * a;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6)
		return(TRUE);
	return(FALSE);
}

int		ft_cylinder_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cylinder	*cyl;
	t_vertex	o;
	t_vertex	d;
	t_vertex	temp;
	t_vertex	oc;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	cyl = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, cyl->center);
	a = d.x * d.x + d.z * d.z;
	b = (2 * d.x * (oc.x)) + (2 * d.z * (oc.z));
	c = (oc.x * oc.x) + (oc.z * oc.z) - cyl->r * cyl->r;
	disc = b * b - 4 * a * c;
	if (disc < 1e-6)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / 2 * a;
	t1 = (-b + disc) / 2 * a;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6 && t0 < all->rt.t)
	{
		all->rt.t = t0;
		all->rt.rgb = cyl->color;
		temp = ft_mult_vec_double(d, all->rt.t);
		all->rt.inter = ft_sum_vector(o, temp);
		ft_get_normal_cylinder(all, cyl);
		return(TRUE);
	}
	return(FALSE);
}