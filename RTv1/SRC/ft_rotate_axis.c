#include "rtv1.h"


void	ft_ox(t_calc calc, t_vertex *ret)
{
	double tmp;

	tmp = ret->y;
	ret->y = ret->y * calc.cos_x + ret->z * calc.sin_x;
	ret->z = -tmp * calc.sin_x + ret->z * calc.cos_x;
}

void	ft_oy(t_calc calc, t_vertex *ret)
{
	double tmp;

	tmp = ret->x;
	ret->x = ret->x * calc.cos_y + ret->z * calc.sin_y;
	ret->z = -tmp * calc.sin_y + ret->z * calc.cos_y;
}

void	ft_oz(t_calc calc, t_vertex *ret)
{
	double tmp;

	tmp = ret->x;
	ret->x = ret->x * calc.cos_z - ret->y * calc.sin_z;
	ret->y = tmp * calc.sin_z + ret->y * calc.cos_z;
}

void	ft_rotate(t_calc calc, t_vertex *ret)
{
	ft_ox(calc, ret);
	ft_oy(calc, ret);
	ft_oz(calc, ret);
}