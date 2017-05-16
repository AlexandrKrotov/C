#include "FdF.h"

int	set_color(t_point_lst *ret, int color)
{
	if (color != 0)
		return (color);
	else if (ret->point.z < 0)
		color = 0x4286f4;
	else if (ret->point.z >= 0 && ret->point.z < 10)
		color = 0x0bff00;
	else if (ret->point.z >= 30 && ret->point.z < 50)
		color = 0xee5f725;
	else if (ret->point.z >= 50 && ret->point.z < 100)
		color = 0xea04c21;
	else if (ret->point.z >= 50 && ret->point.z < 100)
		color = 0xe6e8d0;
	else
		color = STD_COLOR;
	return (color);
}

t_rgb	*get_rgb(t_point_lst *ret, int color)
{
	t_rgb *rgb;

	rgb = malloc(sizeof(t_rgb));
	*rgb = (t_rgb){0};

	color = set_color(ret, color);
	rgb->blue = (unsigned char) ((color & 0xFF0000) >> 16);
	rgb->green = (unsigned char) ((color & 0xFF00) >> 8);
	rgb->red = (unsigned char) (color & 0xFF);
	return (rgb);
}

int 	ft_strtol(char *split)
{
	int 	color;
	char	*ptr;

	color = 0;
	ptr = split;
	while (*ptr != '\0')
	{
		if (*ptr == ',')
		{
			ptr++;
			color = (int) strtol(ptr, 0, 16);
			return (color);
		}
		ptr++;
	}
	return (color);
}

