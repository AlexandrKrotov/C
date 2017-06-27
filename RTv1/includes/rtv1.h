#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>

/*
** GRAPHIC
*/
# include <mlx.h>

/*
************************
*/

# define D_NAME		"RTv1"
# define D_WIDTH	1200
# define D_HEIGHT	900
# define BPP		4
# define TRUE		1
# define FALSE		0


typedef	struct		s_vertex{
	double			x;
	double			y;
	double			z;
}					t_vertex;

typedef struct		s_vector{
	t_vertex		origin;
	t_vertex		direct;
	//double	 	magnitude;
}					t_vector;

typedef struct		s_rgb{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	opacity;
}					t_rgb;

typedef struct		s_objs{
	void			*obj;
	struct	s_objs	*next;
}					t_objs;

typedef struct		s_sphere{
	double			radius;
	t_vertex		center;
	t_rgb			color;
}					t_sphere;

typedef struct 		s_plain{
	t_vector		norma;
	t_rgb			color;
}					t_plain;

typedef struct 		s_dsp{
	int 			dsp_h;
	int 			dsp_w;
}					t_dsp;

typedef struct		s_mlx{
	void			*mlx;
	void			*wnd;
	void			*img;
	char			*gda;
	int				bpp;
	int				size_line;
	int				endian;

}					t_mlx;

typedef struct		s_all{
	t_mlx			*mlx;
	t_dsp			dsp;
	t_objs			*scene;
}					t_all;

void				init_all(t_all *all);
void				ft_crete_lst(t_all *all);

int					ft_render(t_all *all);

int					ft_key_hook(int keycode, t_all *all);

int					ft_mouse_hook(int key, int x, int y, t_all *all);
int 				ft_mouse_cord(int x, int y, t_all *all);

void				ft_sub_vector(t_vertex a, t_vertex b, t_vertex *res);
void				ft_mult_vector2(t_vector *a, t_vector *b, t_vector *res);
void				ft_mult_vector3(t_vertex a, t_vertex b, t_vertex *res);
double				ft_sum_scalar(t_vertex a, t_vertex b);

int					ft_sphere_intersect(t_all *all, t_vector *ray, double *t);

int					ft_exit(void);

#endif
