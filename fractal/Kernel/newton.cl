int			addr(int x, int y, int width)
{
	return (width * y + x) * 4;
}
double		f(double z)
{
    return (z * z * z -1);
}

__kernel	void render(__global char *out, double step_x, double step_y, double re_min, double im_min, double shift_x, double shift_y, int m_iter, int red, int green, int blue, double n_re, double n_im)
{
	double	col = get_global_id(0);
	double	row = get_global_id(1);
	size_t	width = get_global_size(0);
	size_t	height = get_global_size(1);
	double	zx;
	double	zy;
	double	dx;
	double	dy;
	int		iter;
	int		idx;
	double	tmp;

	zx = (re_min + fabs(step_x) * col) + shift_x;
	zy = (im_min + fabs(step_y) * row) - shift_y;
	iter = 0;
	tmp = 1.0;
	while (tmp > 0.0000001 && iter < m_iter)
	{
		dx = zx;
		dy = zy;
		tmp = (zx * zx + zy * zy) * (zx * zx + zy * zy);
		zx = (2 * zx * tmp + zx * zx - zy * zy) /(3.0 * tmp);
		zy = (2 * zy * (tmp - dx)) / (3.0 * tmp);
		tmp = (zx - dx) * (zx - dx) + (zy - dy) * (zy - dy);
		iter++;
	}
	idx = addr(col, row, width);
	out[idx] = iter * red;
	out[idx + 1] = iter * green;
	out[idx + 2] = iter * blue;
	out[idx + 3] = 0;
}
