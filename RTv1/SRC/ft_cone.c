#include "rtv1.h"

void		ft_get_info_cone(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cone		*con;
	t_vertex	a;
	t_vertex	b;
	t_vertex	scaled;
	t_vertex	tmp;

	con = ptr->obj;
	tmp = ft_mult_vec_double(ray->d, all->rt.t);
	all->rt.inter = ft_sum_vector(ray->o, tmp);
	b = ft_sub_vector(all->rt.inter, con->ray.o);
	a = ft_mult_vec_double(con->ray.d, ft_cos_vector(b, con->ray.d));
	all->rt.norm = ft_sub_vector(b, a);
	scaled = ft_cross_vector(b, all->rt.norm);
	all->rt.norm = ft_cross_vector(scaled, b);
	all->rt.norm = ft_normalized_vector(all->rt.norm);
	all->rt.rgb = con->color;
}

int		ft_cone_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cone		*con;
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
	oc = ft_sub_vector(ray->o, con->ray.o);
	dot_v = ft_dot_product(ray->d, con->ray.d);
	dot_p = ft_dot_product(oc, con->ray.d);
	av = ft_sub_vector(ray->d, ft_mult_vec_double(con->ray.d, dot_v));
	cv = ft_sub_vector(oc, ft_mult_vec_double(con->ray.d, dot_p));
	a = con->cos2 * ft_dot_product(av, av) - con->sin2 * (dot_v * dot_v);
	b = 2 * con->cos2 * ft_dot_product(av, cv) - 2 * con->sin2 * (dot_v) * (dot_p);
	c = con->cos2 * ft_dot_product(cv, cv) - con->sin2 * (dot_p * dot_p);
	disc = b * b - 4 * a * c;
	if (disc < 1e-6)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b - disc) / (2 * a);
	t1 = (-b + disc) / (2 * a);
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6 && t0 < all->rt.t)
	{
		all->rt.t = t0;
		return(TRUE);
	}
	return(FALSE);
}