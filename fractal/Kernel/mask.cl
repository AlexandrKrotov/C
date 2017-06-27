#ifdef cl_khr_fp64
#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#elif defined(cl_amd_fp64)
#pragma OPENCL EXTENSION cl_amd_fp64 : enable
#else
#error "Double precision floating point not supported by OpenCL implementation."
#endif

int			index(int x, int y, int width)
{
  return (width * y + x) * 4;
}

__kernel	void render(__global char *out, double step_x, double step_y, double re_min, double im_min, double shift_x, double shift_y, int m_iter, int red, int green, int blue, double n_re, double n_im)
{
	double	col = get_global_id(0);
	double	row = get_global_id(1);
	size_t	width = get_global_size(0);
	size_t	height = get_global_size(1);
	int		idx = index(col, row, width);
	double	x_new = 0;
	double	x;
	double	y;
	double	c_re;
	double	c_im;
	int		iter;

	x = re_min + col * step_x + shift_x;
	y = im_min + row * step_y - shift_y;
	c_re = -0.7 + (-0.7 - n_re);
	c_im = 0.27015 - (0.27015 + n_im);
	iter = 0;
	while (x * x + y * y <= 4 && iter < m_iter)
	{
		x_new = x * x - y * y + c_re;
		y = cos(2 * x * y) + c_im;
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
