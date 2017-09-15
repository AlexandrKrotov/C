#include "rtv1.h"


t_cone *ft_init_cone(t_vertex ray_o, t_vertex ray_d, t_rgb color, double angle)
{
	t_cone *cone;

	cone = malloc(sizeof(t_cone));
	cone->ray.o = ray_o;
	cone->ray.d = ray_d;
	cone->color = color;
	cone->alpha = angle;
	cone->rad = cone->alpha * M_PI / 180;
	cone->cos2 = cos(cone->rad) * cos(cone->rad);
	cone->sin2 = sin(cone->rad) * sin(cone->rad);
	cone->n = 20;
	cone->amb_int = 0.1;
	cone->dif_int = 1;
	cone->spc_int = 1;

	return (cone);
}

void	ft_add_cone(t_objs *scene, t_vertex ray_o, t_vertex ray_d, t_rgb color, double angle)
{
	t_objs *ptr;

	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_cone(ray_o, ray_d, color, angle);
	ptr->ft_inter = ft_cone_intersect;
	ptr->ft_info = ft_get_info_cone;
}

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
	all->rt.n = con->n;
	all->rt.amb_int = con->amb_int;
	all->rt.dif_int = con->dif_int;
	all->rt.spc_int = con->spc_int;
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