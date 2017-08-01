#include "rtv1.h"

void	ft_ptr_to_rgb(char *ptr, t_rgb *rgb)
{
	rgb->b = (unsigned char)(256 + *ptr++);
	rgb->g = (unsigned char)(256 + *ptr++);
	rgb->r = (unsigned char)(256 + *ptr);
	rgb->opacity = 0;
}

void	ft_antialiasing(t_mlx *mlx)
{
	int 	x;
	int 	y;
	int 	size;
	char	*ptr;
	t_rgb 	color_1;
	t_rgb 	color_2;
	t_rgb 	color_3;
	t_rgb 	color_4;
	t_irgb	mid;

	y = 0;
	while (y < D_HEIGHT)
	{
		x = 0;
		while (x < D_WIDTH)
		{
			color_1 = (t_rgb){0,0,0,0};
			color_2 = (t_rgb){0,0,0,0};
			color_3 = (t_rgb){0,0,0,0};
			color_4 = (t_rgb){0,0,0,0};
			mid = (t_irgb){0,0,0};
			size = 1;
			if (y - 1 >= 0)
			{
				ptr = (mlx->img.gda + (y - 1) * mlx->img.size_line + x * 4);
				ft_ptr_to_rgb(ptr, &color_1);
				size++;
			}
			if (x + 1 < D_WIDTH)
			{
				ptr = (mlx->img.gda + y * mlx->img.size_line + (x + 1) * 4);
				ft_ptr_to_rgb(ptr, &color_2);
				size++;
			}
			if (y + 1 < D_HEIGHT)
			{
				ptr = (mlx->img.gda + (y + 1) * mlx->img.size_line + x * 4);
				ft_ptr_to_rgb(ptr, &color_3);
				size++;

			}
			if (x - 1 >= 0)
			{
				ptr = (mlx->img.gda + y * mlx->img.size_line + (x - 1) * 4);
				ft_ptr_to_rgb(ptr, &color_4);
				size++;
			}
			ptr = (mlx->img.gda + y * mlx->img.size_line + x * 4);
			mid.b = (unsigned char)(256 + *ptr++);
			mid.g = (unsigned char)(256 + *ptr++);
			mid.r = (unsigned char)(256 + *ptr);
			mid.r = mid.r + color_1.r + color_2.r +  color_3.r + color_4.r;
			mid.g = mid.g + color_1.g + color_2.g +  color_3.g + color_4.g;
			mid.b = mid.b + color_1.b + color_2.b +  color_3.b + color_4.b;
			mid.r /= size;
			mid.g /= size;
			mid.b /= size;
			ptr = (mlx->img_a.gda + y * mlx->img.size_line + x * 4);
			ptr[0] = (char)mid.b;
			ptr[1] = (char)mid.g;
			ptr[2] = (char)mid.r;
			x++;
		}
		y++;
	}
}
