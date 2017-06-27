#include "rtv1.h"

void	ft_sum_vector(t_vertex *a, t_vertex *b, t_vertex *res)
{
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
}

void	ft_sub_vector(t_vertex a, t_vertex b, t_vertex *res)
{
	res->x = b.x - a.x;
	res->y = b.y - a.y;
	res->z = b.z - a.z;
}

void	ft_mult_vector(t_vector *a, t_vector *b, t_vector *res)
{
	res->origin.x = (a->origin.y * b->origin.z) - (a->origin.z * b->origin.y);
	res->origin.y = (a->origin.z * b->origin.x) - (a->origin.x * b->origin.z);
	res->origin.z = (a->origin.x * b->origin.y) - (a->origin.y * b->origin.x);
}

void	ft_mult_vector3(t_vertex a, t_vertex b, t_vertex *res)
{
	res->x = (a.y * b.z) - (a.z * b.y);
	res->y = (a.z * b.x) - (a.x * b.z);
	res->z = (a.x * b.y) - (a.y * b.x);
}

double	ft_sum_scalar(t_vertex a, t_vertex b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}