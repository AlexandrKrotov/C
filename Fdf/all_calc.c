#include "FdF.h"

void	ft_calc_all(t_all *all)
{
	all->calc->cos_x = cos(all->trans.angle_x / 180 * M_PI);
	all->calc->cos_y = cos(all->trans.angle_y / 180 * M_PI);
	all->calc->cos_z = cos(all->trans.angle_z / 180 * M_PI);
	all->calc->sin_x = sin(all->trans.angle_x / 180 * M_PI);
	all->calc->sin_y = sin(all->trans.angle_y / 180 * M_PI);
	all->calc->sin_z = sin(all->trans.angle_z / 180 * M_PI);
	all->calc->shift_w = (all->half_w) + all->trans.shift.x_shift;
	all->calc->shift_h = (all->half_h) + all->trans.shift.y_shift;
	all->calc->shift_x = (all->width * all->m_x_s_x / 2);
	all->calc->shift_y = (all->height * all->m_y_s_y / 2);
}
