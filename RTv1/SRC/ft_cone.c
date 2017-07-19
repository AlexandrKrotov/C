#include "rtv1.h"

t_vertex		ft_get_normal_at_cone(t_all *all, t_cone *cone)
{

	all->rt.norm = ft_normalized_vector(ft_sum_vector(all->rt.inter, ft_reverse_vector(cone->center)));
}

int		ft_cone_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cone		*con;
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

	con = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	oc = ft_sub_vector(o, con->center);
	a = (d.x * d.x) - (d.y * d.y) + (d.z * d.z);
	b = (2 * d.x * oc.x) - (2 * d.y * oc.y) + (2 * d.z * oc.z);
	c = (oc.x * oc.x) - (oc.y * oc.y) + (oc.z * oc.z);
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