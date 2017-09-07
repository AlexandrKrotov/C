#include "fractal.h"


void	julia_new(t_all *all, double step_x, double step_y, double re_min, double im_min, double shift_x, double shift_y, int m_iter)
{
	double cRe = -0.7 + all->jul.c_re;
	double cIm = 0.27015 + all->jul.c_im;
	double r, im, t;
	double y;
	double x;
	int i, j, it;

	y = im_min - shift_y;
	x = re_min - shift_x;
	i = 0;
//	printf("y: %f x: %f\n" ,y, x);
	while (i < D_HEIGHT)
	{
		j = 0;
		x = re_min - shift_x;
		while (j < D_WIDTH)
		{
			r = x;
			im = y;
			it = 0;
			while (it < m_iter && r * r + im * im < 4)
			{
				t = r * r - im * im + cRe;
				im = 2 * r * im + cIm;
				r = t;
				it++;
			}
			if (it == m_iter)
				ft_put_color(all, j, i, 0);
			else
				ft_put_color(all, j, i, it);
			x += step_x;
			j++;
		}
		y += step_y;
		i++;
	}
}
