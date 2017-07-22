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
# define D_WIDTH	800
# define D_HEIGHT	600
# define BPP		4
# define TRUE		1
# define FALSE		0

/*
** KEY_DEFINE
*/

#ifdef __linux

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define Z 122
# define X 120
# define UP 65362
# define DOWN 65364

#else __APPLE__

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define Z 6
# define X 7
# define UP 126
# define DOWN 125

#endif

typedef struct		s_all t_all;
typedef struct		s_objs t_objs;

typedef	struct		s_vertex{
	double			x;
	double			y;
	double			z;
}					t_vertex;

typedef struct		s_rgb{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	opacity;
}					t_rgb;

typedef struct		s_ray{
	t_vertex		origin;
	t_vertex		direct;
	//double	 	magnitude;
}					t_ray;

typedef	struct		s_rt{
	double			t;
	double			brightness;
	t_vertex		norm;
	t_vertex		inter;
	t_rgb			rgb;
}					t_rt;

typedef struct		s_sphere{
	double			radius;
	double			r2;
	t_vertex		center;
	t_rgb			color;
}					t_sphere;

typedef struct		s_plane{
	double          d;
	t_vertex		norm;
	t_rgb			color;
}					t_plane;

typedef struct		s_cylinder{
	t_vertex		center;
	t_vertex		dir;
	double 			r;
	double 			r2;
	t_rgb 			color;
}					t_cylinder;

typedef struct 		s_flags{
	int 			redraw;
}					t_flags;

typedef struct		s_cone{
	t_vertex		center;
	t_vertex		dir;
	t_rgb 			color;
	double 			alpha;
	double 			rad;
	double			cos2;
	double			sin2;
}					t_cone;

typedef struct		s_dsp{
	int				dsp_h;
	int				half_h;
	int				dsp_w;
	int				half_w;
	int				rend_ws;
	int				rend_hs;
	int				rend_we;
	int				rend_he;
}					t_dsp;

typedef struct		s_trans{
	double 			zoom;
}					t_trans;

typedef	struct 		s_light{
	t_vertex		light;
	double 			angle;
	double 			power;
	struct s_light	*next;
}					t_light;

typedef struct		s_mlx{
	void			*mlx;
	void			*wnd;
	void			*img;
	char			*gda;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_objs{
	void			*obj;
	int 			(*ft_inter)(t_all*, t_ray*, t_objs*);
	int 			(*ft_shadow)(t_ray*, t_objs*);
	struct	s_objs	*next;
}					t_objs;

typedef struct		s_all{
	t_mlx			*mlx;
	t_dsp			dsp;
	t_objs			*scene;
	t_vertex 		light;
	t_light 		light_list;
	t_vertex		cam;
	t_rt			rt;
	t_trans			trans;
	t_flags			flags;
}					t_all;

void				init_all(t_all *all);
void				ft_crete_lst(t_all *all);

int					ft_render(t_all *all);

int					ft_key_hook(int keycode, t_all *all);

int					ft_mouse_hook(int key, int x, int y, t_all *all);
int 				ft_mouse_cord(int x, int y, t_all *all);

t_vertex			ft_sub_vector(t_vertex a, t_vertex b);
t_vertex			ft_sum_vector(t_vertex a, t_vertex b);
double				ft_dot_product(t_vertex a, t_vertex b);
double				ft_get_magnitude(t_vertex a);
t_vertex			ft_normalized_vector(t_vertex a);
t_vertex			ft_mult_vec_double(t_vertex a, double b);
t_vertex			ft_devide_vec_double(t_vertex a, double b);
t_vertex			ft_reverse_vector(t_vertex v1);


int					ft_sphere_intersect(t_all *all, t_ray *ray, t_objs *ptr);
int					ft_plane_intersect(t_all *all, t_ray *ray, t_objs *ptr);
int					ft_cylinder_intersect(t_all *all, t_ray *ray, t_objs *ptr);
int					ft_cone_intersect(t_all *all, t_ray *ray, t_objs *ptr);

int					ft_sphere_shadowray(t_ray *ray, t_objs *ptr);
int					ft_plane_shadowray(t_ray *ray, t_objs *ptr);
int					ft_cylinder_shadowray(t_ray *ray, t_objs *ptr);
int					ft_cone_shadowray(t_ray *ray, t_objs *ptr);



int					ft_exit(void);

#endif