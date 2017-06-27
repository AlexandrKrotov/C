int			addr(int x, int y, int width)
{
	return (width * y + x) * 4;
}

__kernel	void render(__global char *out, double step_x, double step_y, double re_min, double im_min, double shift_x, double shift_y, int m_iter, int red, int green, int blue, double n_re, double n_im)
{
	double	col = get_global_id(0);
	double	row = get_global_id(1);
	size_t	width = get_global_size(0);
	size_t	height = get_global_size(1);
	int		idx = addr(col, row, width);
	double	x_new = 0;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		iter;

	c_re =	(re_min + step_x * col) + shift_x;
	c_im =	(im_min + step_y * row) - shift_y;
	x = 0 - n_re;
	y = 0 + n_im;
	iter = 0;
	while (x * x + y * y <= 4 && iter < m_iter)
	{
		x_new = (x * x - y * y) + c_re;
		y = 2 * (x * y) + c_im;
		x = x_new;
		iter++;
	}
	if (iter == m_iter)
	{
		out[idx] = 0;
		out[idx + 1] = 0;
		out[idx + 2] = 0;
		out[idx + 3] = 0;
	}
	else
	{
		out[idx] = iter * red;
		out[idx + 1] = iter * green;
		out[idx + 2] = iter * blue;
		out[idx + 3] = 0;
	}
}
