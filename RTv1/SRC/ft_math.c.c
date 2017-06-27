#include "rtv1.h"

double	ft_get_magnitude(double x, double y, double z)
{
	double		ret;

	ret = fabs(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
	return (ret);
}

//double	ft_cos_alpha(t_vector a, t_vector b, double scl_sum)
//{
//	return (scl_sum / (a.magnitude * b.magnitude));
//}