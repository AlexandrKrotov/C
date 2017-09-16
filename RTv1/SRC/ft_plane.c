#include "rtv1.h"

t_plane	*ft_init_plane(t_vertex ray_o, t_vertex ray_d, t_rgb color)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	plane->ray.d = ray_d;
	plane->ray.o = ray_o;
	plane->color = color;
	plane->n = 20;
	plane->amb_int = 0.1;
	plane->dif_int = 0.6;
	plane->spc_int = 1;

	return (plane);
}

void ft_add_plane(t_objs *scene, t_vertex ray_o, t_vertex ray_d, t_rgb color)
{
	t_objs		*ptr;

	ptr = ft_find_empty(scene, ptr);
	ptr->obj = ft_init_plane(ray_o, ray_d, color);
	ptr->ft_inter = ft_plane_intersect;
	ptr->ft_info = ft_get_info_plane;
}

void	ft_get_info_plane(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_plane		*p;
	t_vertex	tmp;

	p = ptr->obj;
	all->rt.rgb = p->color;
	tmp = ft_mult_vec_double(ray->d, all->rt.t);
	all->rt.inter = ft_sum_vector(ray->o, tmp);
	all->rt.norm = p->ray.d;
	all->rt.n = p->n;
	all->rt.amb_int = p->amb_int;
	all->rt.dif_int = p->dif_int;
	all->rt.spc_int = p->spc_int;
	all->rt.plane = 1;
}

int		ft_plane_intersect(t_all *all, t_ray *ray, t_objs *ptr)
{
	t_plane     *p;
	t_vertex	oc;
	double		b;
	double		t;

	p = ptr->obj;
	b = (ft_dot_product(ray->d, p->ray.d));
	if (b  != 0)
	{
		oc = ft_sub_vector(p->ray.o, ray->o);
		t = ft_dot_product(oc, p->ray.d);
		t = (t / b);
	}
	else
		return (FALSE);
	if (t > 1e-6 && t < all->rt.t)
	{
		all->rt.t = t - 1e-6;
		return(TRUE);
	}
	return(FALSE);
}