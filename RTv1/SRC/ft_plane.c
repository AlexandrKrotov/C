#include "rtv1.h"


int		ft_plane_shadowray(t_all *all,t_ray *ray, t_objs *ptr)
{
	t_plane     *p;
	t_vertex	o;
	t_vertex	d;
	double		b;
	double		t;

	p = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	b = ft_dot_product(p->norm, d);
	if (b != 0)
	{
		t = -ft_dot_product(p->norm, o) - p->d;
		t = t / b;
	}
	else
		return (FALSE);
	if (t > 1e-6)
		return(TRUE);
	return(FALSE);
}

int		ft_plane_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_plane     *p;
	t_vertex	o;
	t_vertex	d;
	t_vertex	temp;
	double		b;
	double		t;

	p = ptr->obj;
	o = ray->origin;
	d = ray->direct;
	b = ft_dot_product(p->norm, d);

	if (b != 0)
	{
		t = -ft_dot_product(p->norm, o) - p->d;
		t = t / b;
	}
	else
		return (FALSE);
	if (t > 1e-6 && t < all->rt.t)
	{
		all->rt.t = t;
		all->rt.rgb = p->color;
		temp = ft_mult_vec_double(d, all->rt.t);
		all->rt.inter = ft_sum_vector(o, temp);
		all->rt.norm = p->norm;
		return(TRUE);
	}
	return(FALSE);
}