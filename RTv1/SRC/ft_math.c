#include "rtv1.h"


t_vertex	ft_reverse_vector(t_vertex v1)
{
	t_vertex	ret;

	ret = (t_vertex){v1.x * -1, v1.y * -1, v1.z * -1};
	return (ret);
}