#include "rtv1.h"

void	ft_get_normal_cylinder(t_all *all, t_cylinder *cylinder)
{
	t_vertex a;
	t_vertex gip;
	t_vertex bn;

	gip = ft_sub_vector(all->rt.inter, cylinder->center);
	a = ft_mult_vec_double(cylinder->dir, ft_dot_product(gip, cylinder->dir));
	bn = ft_sub_vector(gip, a);
	all->rt.norm = ft_normalized_vector(bn);
}

int		ft_cylinder_shadowray(t_ray *ray, t_objs *ptr)
{
	t_cylinder	*cyl;
	t_vertex	o;
	t_vertex	d;
	t_vertex	oc;
	double		a;
	t_vertex	av;
	t_vertex	cv;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	cyl = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, cyl->center);

	av = ft_sub_vector(d, ft_mult_vec_double(cyl->dir, ft_dot_product(d, cyl->dir)));
	cv = ft_sub_vector(oc, ft_mult_vec_double(cyl->dir, ft_dot_product(oc, cyl->dir)));
	a = ft_dot_product(av, av);
	b = 2 * ft_dot_product(av, cv);
	c = ft_dot_product(cv, cv) - cyl->r2;
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
	t_vertex	oc;
	t_vertex	av;
	t_vertex	cv;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;
	t_vertex	temp;

	cyl = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, cyl->center);

	av = ft_sub_vector(d, ft_mult_vec_double(cyl->dir, ft_dot_product(d, cyl->dir)));
	cv = ft_sub_vector(oc, ft_mult_vec_double(cyl->dir, ft_dot_product(oc, cyl->dir)));
	a = ft_dot_product(av, av);
	b = 2 * ft_dot_product(av, cv);
	c = ft_dot_product(cv, cv) - cyl->r2;
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