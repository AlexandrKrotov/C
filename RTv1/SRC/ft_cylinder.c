#include "rtv1.h"

t_cylinder		*ft_init_cylinder(t_vertex ray_o, t_vertex ray_d, t_rgb color, double radius)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->ray.o = ray_o;
	cylinder->ray.d = ray_d;
	cylinder->r = radius;
	cylinder->r2 = cylinder->r * cylinder->r;
	cylinder->color = color;
	cylinder->n = 30;
	cylinder->amb_int = 0.1;
	cylinder->dif_int = 1;
	cylinder->spc_int = 1;

	return (cylinder);
}

void	ft_add_cylinder(t_objs *scene, t_vertex ray_o, t_vertex ray_d, t_rgb color, double radius)
{
	t_objs *ptr;

	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_cylinder(ray_o, ray_d, color, radius);
	ptr->ft_inter = ft_cylinder_intersect;
	ptr->ft_info = ft_get_info_cylinder;
}

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
	all->rt.n = cyl->n;
	all->rt.amb_int = cyl->amb_int;
	all->rt.dif_int = cyl->dif_int;
	all->rt.spc_int = cyl->spc_int;
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