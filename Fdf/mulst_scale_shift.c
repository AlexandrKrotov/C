#include "FdF.h"

void ft_mult_and_scale(const t_all *all, t_point_lst *lst0, t_point_lst *lst1,
					   t_line_cord *ret)
{
	ret->x0 = (lst0->point.x  * all->m_x_s_x - all->calc->shift_x);
	ret->y0 = (lst0->point.y * all->m_y_s_y - all->calc->shift_y);
	ret->z0 = lst0->point.z;
	ret->x1 = (lst1->point.x * all->m_x_s_x - all->calc->shift_x);
	ret->y1 = (lst1->point.y * all->m_y_s_y - all->calc->shift_y);
	ret->z1 = lst1->point.z;
}

void move_centr_scale(const t_all *all, t_line_cord *ret)
{
	ret->x0 = ret->x0  * all->trans.scale + all->calc->shift_w;
	ret->y0 = ret->y0  * all->trans.scale + all->calc->shift_h;
	ret->x1 = ret->x1  * all->trans.scale + all->calc->shift_w;
	ret->y1 = ret->y1  * all->trans.scale + all->calc->shift_h;
}

