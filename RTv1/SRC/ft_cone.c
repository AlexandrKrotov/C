#include "rtv1.h"

t_vertex		ft_get_normal_at_cone(t_all *all, t_cone *cone)
{
	all->rt.norm = ft_normalized_vector(ft_sum_vector(all->rt.inter, ft_reverse_vector(cone->center)));
}

int		ft_cone_shadowray(t_ray *ray, t_objs *ptr)
{
	t_cone		*con;
	t_vertex	o;
	t_vertex	d;
	t_vertex	oc;
	t_vertex	av;
	t_vertex	cv;
	double		dot_v;
	double		dot_p;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	con = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, con->center);
	dot_v = ft_dot_product(d, con->dir);
	dot_p = ft_dot_product(oc, con->dir);
	av = ft_sub_vector(d, ft_mult_vec_double(con->dir, dot_v));
	cv = ft_sub_vector(oc, ft_mult_vec_double(con->dir, dot_p));
	a = con->cos2 * ft_dot_product(av, av) - con->sin2 * (dot_v * dot_v);
	b = 2 * con->cos2 * ft_dot_product(av, cv) - 2 * con->sin2 * (dot_v) * (dot_p);
	c = con->cos2 * ft_dot_product(cv, cv) - con->sin2 * (dot_p * dot_p);
	disc = b * b - 4 * a * c;
	if (disc < 1e-6)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / 2 * a;
	t1 = (-b + disc) / 2 * a;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6)
	disc = sqrt(disc);
	t0 = (-b - disc) / 2 * a;
	t1 = (-b + disc) / 2 * a;
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6)
		return(TRUE);
	return(FALSE);
}

int		ft_cone_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cone		*con;
	t_vertex	o;
	t_vertex	d;
	t_vertex	temp;
	t_vertex	oc;
	t_vertex	av;
	t_vertex	cv;
	double		dot_v;
	double		dot_p;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	con = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, con->center);
	dot_v = ft_dot_product(d, con->dir);
	dot_p = ft_dot_product(oc, con->dir);
	av = ft_sub_vector(d, ft_mult_vec_double(con->dir, dot_v));
	cv = ft_sub_vector(oc, ft_mult_vec_double(con->dir, dot_p));
	a = con->cos2 * ft_dot_product(av, av) - con->sin2 * (dot_v * dot_v);
	b = 2 * con->cos2 * ft_dot_product(av, cv) - 2 * con->sin2 * (dot_v) * (dot_p);
	c = con->cos2 * ft_dot_product(cv, cv) - con->sin2 * (dot_p * dot_p);
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
		all->rt.rgb = con->color;
		temp = ft_mult_vec_double(d, all->rt.t);
		all->rt.inter = ft_sum_vector(o, temp);
		ft_get_normal_at_cone(all, con);
		return(TRUE);
	}
	return(FALSE);
}