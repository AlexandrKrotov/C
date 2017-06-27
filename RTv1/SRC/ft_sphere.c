#include "rtv1.h"


int		ft_sphere_intersect(t_all *all, t_vector *ray, double *t)
{
	t_sphere *s = all->scene->obj;
	t_vertex o = ray->origin;
	t_vertex d = ray->direct;
	t_vertex *oc =malloc(sizeof(t_vertex));
	ft_sub_vector(o, s->center, oc);
	double b =  2 * ft_sum_scalar(*oc, d);
	double c = ft_sum_scalar(*oc, *oc) - s->radius * s->radius;
	double disc = b * b - 4 * c;
	free(oc);
	if (disc < 1e-4)
		return (FALSE);
	disc = sqrt(disc);
	double t0 = -b - disc;
	double t1 = -b + disc;
	*t = (t0 < t1) ? t0 : t1;
	return (TRUE);
}
