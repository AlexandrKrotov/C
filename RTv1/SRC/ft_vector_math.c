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

t_vertex	ft_divide_vec_double(t_vertex a, double b)
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


double		ft_cos_vector(t_vertex u, t_vertex v)
{
	double	a;
	double	b;
	double	c;

	a = ft_dot_product(u , v);
	b = ft_dot_product(u, u);
	c = ft_dot_product(v,v);
	return (a / (b * c));
}

t_vertex	ft_cross_vector(t_vertex a, t_vertex b)
{
	t_vertex ret;

	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);

	return (ret);
}

t_vertex	ft_reverse_vector(t_vertex a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	return (a);
}

t_vertex	ft_reflect_vector(t_vertex a, t_vertex b)
{
	t_vertex ret;

	ret = ft_mult_vec_double(b, 2 * (ft_dot_product(a,b)));
	ret = ft_sub_vector(ret, a);
	return (ret);
}