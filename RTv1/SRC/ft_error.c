#include <rtv1.h>

void ft_error(int error)
{
	if (error == 11)
		ft_putstr("Code error: 11. Wrong number of quantity for ft_antialising.");
	exit(error);
}