#include "rtv1.h"

void	ft_ptr_to_rgb(char *ptr, t_rgb *rgb)
{
	rgb->b = (unsigned char)(256 + *ptr++);
	rgb->g = (unsigned char)(256 + *ptr++);
	rgb->r = (unsigned char)(256 + *ptr);
	rgb->opacity = 0;
}

int		ft_set_color(const char *data_in, t_rgb *color, int x, int y, int size)
{
	char	*ptr;

	ptr = (char *)(data_in + y * SIZE_LINE + x * 4);
	ft_ptr_to_rgb(ptr, color);
	size++;
	return (size);
}

int		init_color_arr(const char *data_in, const t_cord *xy, t_rgb *color)
{
	int		size;

	size = 0;
	size = ft_set_color(data_in, &color[0], xy->x, xy->y, size);
	if (xy->y - 1 >= 0)
		size = ft_set_color(data_in, &color[1], xy->x, xy->y, size);
	if (xy->y - 1 >= 0 && xy->x + 1 < D_WIDTH)
		size = ft_set_color(data_in, &color[2], xy->x + 1, xy->y - 1, size);
	if (xy->x + 1 < D_WIDTH)
		size = ft_set_color(data_in, &color[3], xy->x + 1, xy->y, size);
	if (xy->y + 1 < D_HEIGHT && xy->x + 1 < D_WIDTH)
		size = ft_set_color(data_in, &color[4], xy->x + 1, xy->y + 1, size);
	if (xy->y + 1 < D_HEIGHT)
		size = ft_set_color(data_in, &color[5], xy->x, xy->y + 1, size);
	if (xy->y + 1 < D_HEIGHT && xy->x - 1 >= 0)
		size = ft_set_color(data_in, &color[6], xy->x - 1, xy->y + 1, size);
	if (xy->x - 1 >= 0)
		size = ft_set_color(data_in, &color[7], xy->x - 1, xy->y, size);
	if (xy->y - 1 >= 0 && xy->x - 1 >= 0)
		size = ft_set_color(data_in, &color[8], xy->x - 1, xy->y - 1, size);
	return (size);
}

void	init_value(t_rgb *color)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		color[i] = (t_rgb){0, 0, 0, 0};
		i++;
	}
}

void	calc_mid_color(char *data_o, t_rgb *color, int size, const t_cord *xy)
{
	t_irgb	mid;
	int		i;
	char	*ptr;

	mid = (t_irgb){0, 0, 0};
	i = 0;
	while (i <= 8)
	{
		mid.r += color[i].r;
		mid.g += color[i].g;
		mid.b += color[i].b;
		i++;
	}
	mid.r /= size;
	mid.g /= size;
	mid.b /= size;
	ptr = (data_o + xy->y * SIZE_LINE + xy->x * 4);
	ptr[0] = (char)mid.b;
	ptr[1] = (char)mid.g;
	ptr[2] = (char)mid.r;
}

void	ft_one_loop(const char *data_in, char *data_out)
{
	t_cord	*xy;
	t_rgb	color[8];
	int		size;

	xy = malloc(sizeof(t_cord));
	xy->y = 0;
	while (xy->y < D_HEIGHT)
	{
		xy->x = 0;
		while (xy->x < D_WIDTH)
		{
			init_value(color);
			size = init_color_arr(data_in, xy, color);
			calc_mid_color(data_out, color, size, xy);
			xy->x++;
		}
		xy->y++;
	}
	free(xy);
}

void	ft_antialiasing(char *data_in, int n)
{
	char	*data_out;

	data_out = malloc(sizeof(char) * D_HEIGHT * SIZE_LINE);
	if (n % 2 != 0)
		ft_error(11);
	while (n > 0)
	{
		ft_one_loop(data_in, data_out);
		ft_memcpy(data_in, data_out, (size_t)(D_HEIGHT * SIZE_LINE));
		n -= 2;
	}
	free(data_out);
}
