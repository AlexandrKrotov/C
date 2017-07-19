#include "rtv1.h"

t_vertex	ft_sum_vector(t_vertex a, t_vertex b)
{
	t_vertex	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return(ret);
}

t_vertex	ft_sub_vector(t_vertex a, t_vertex b)
{
	t_vertex	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return(ret);
}

t_vertex	ft_normalized_vector(t_vertex a)
{
	t_vertex	ret;
	double		b;

	b = ft_get_magnitude(a);
	ret.x = a.x / b;
	ret.y = a.y / b;
	ret.z = a.z / b;
	return(ret);
}

t_vertex	ft_devide_vec_double(t_vertex a, double b)
{
	t_vertex	ret;

	ret.x = a.x / b;
	ret.y = a.y / b;
	ret.z = a.z / b;
	return(ret);
}

t_vertex	ft_mult_vec_double(t_vertex a, double b)
{
	t_vertex	ret;

	ret.x = a.x * b;
	ret.y = a.y * b;
	ret.z = a.z * b;
	return(ret);
}
double		ft_dot_product(t_vertex a, t_vertex b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		ft_get_magnitude(t_vertex a)
{
	double	ret;

	ret = fabs(sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
	return (ret);
}
