#include "rtv1.h"

void	ft_get_info_cylinder(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cylinder	*cyl;
	t_vertex	a;
	t_vertex	gip;
	t_vertex	bn;
	t_vertex	tmp;

	cyl = ptr->obj;
	tmp = ft_mult_vec_double(ray->d, all->rt.t);
	all->rt.inter = ft_sum_vector(ray->o, tmp);

	gip = ft_sub_vector(all->rt.inter, cyl->ray.o);
	a = ft_mult_vec_double(cyl->ray.d, ft_dot_product(gip, cyl->ray.d));
	bn = ft_sub_vector(gip, a);
	all->rt.norm = ft_normalized_vector(bn);
	all->rt.rgb = cyl->color;
}

int		ft_cylinder_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_cylinder	*cyl;
	t_vertex	oc;
	t_vertex	av;
	t_vertex	cv;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;

	cyl = ptr->obj;
	oc = ft_sub_vector(ray->o, cyl->ray.o);
	av = ft_sub_vector(ray->d, ft_mult_vec_double(cyl->ray.d, ft_dot_product(ray->d, cyl->ray.d)));
	cv = ft_sub_vector(oc, ft_mult_vec_double(cyl->ray.d, ft_dot_product(oc, cyl->ray.d)));
	a = ft_dot_product(av, av);
	b = 2 * ft_dot_product(av, cv);
	c = ft_dot_product(cv, cv) - cyl->r2;
	disc = b * b - 4 * a * c;
	if (disc < 1e-6)
		return(FALSE);
	disc = sqrt(disc);
	t0 = (-b + disc) / (2 * a);
	t1 = (-b - disc) / (2 * a);
	t0 = (t0 < t1 && (t0 > 0 || t1 > 0)) ? t0 : t1;
	if (t0 > 1e-6 && t0 < all->rt.t)
	{
		all->rt.t = t0;
		return(TRUE);
	}
	return(FALSE);
}