#include "FdF.h"

void ft_key_axis(int keycode, t_all *all)
{
	if (keycode == 12)
		all->trans.angle_z -= 1.0;
	if (keycode == 14)
		all->trans.angle_z += 1.0;
	if (keycode == 13)
		all->trans.angle_x -= 1.0;
	if (keycode == 1)
		all->trans.angle_x += 1.0;
	if (keycode == 2)
		all->trans.angle_y -= 1.0;
	if (keycode == 0)
		all->trans.angle_y += 1.0;
}

void ft_shift(int keycode, t_all *all)
{
	if (keycode == 124)
		all->trans.shift.x_shift += 10;
	if (keycode == 123)
		all->trans.shift.x_shift -= 10;
	if (keycode == 125)
		all->trans.shift.y_shift += 10;
	if (keycode == 126)
		all->trans.shift.y_shift -= 10;
}
void ft_key_color(int keycode, t_all *all)
{
	if(all->trans.r_color > -128)
		all->trans.r_color--;
	if (keycode == 84)
		if(all->trans.g_color > -128)
			all->trans.g_color--;
	if (keycode == 85)
		if(all->trans.b_color > -128)
			all->trans.b_color--;
	if (keycode == 86)
		if (all->trans.r_color < 127)
			all->trans.r_color++;
	if (keycode == 87)
		if (all->trans.g_color < 127)
			all->trans.g_color++;
	if (keycode == 88)
		if (all->trans.b_color < 127)
			all->trans.b_color++;
}

void ft_key_clear_and_scale(int keycode,t_all *all)
{
	if (keycode == 24)
	{
		all->trans.scale += 0.05;
		if (all->trans.scale <= 0)
			all->trans.scale = 0.001;
	}
	if (keycode == 27)
	{
		all->trans.scale -= 0.05;
		if (all->trans.scale <= 0)
			all->trans.scale = 0.001;
	}
	if (keycode == 49)
	{
		all->trans.angle_x = 0;
		all->trans.angle_y = 0;
		all->trans.angle_z = 0;
		all->trans.shift.x_shift = 0;
		all->trans.shift.y_shift = 0;
		all->trans.scale = 1;
		all->trans.r_color = 0;
		all->trans.g_color = 0;
		all->trans.b_color = 0;
	}
}

int	ft_key_hook(int keycode, t_all *all)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	ft_shift(keycode, all);
	ft_key_axis(keycode, all);
	ft_key_color(keycode, all);
	ft_key_clear_and_scale(keycode, all);
	if(keycode == 15)
	{
		if (all->animation == 0)
			all->animation = 1;
		else
			all->animation = 0;
	}
	create_img(all);
	return (0);
}








