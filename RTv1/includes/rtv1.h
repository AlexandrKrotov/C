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
# define SIZE_LINE  D_WIDTH * 4
# define TRUE		1
# define FALSE		0
# define SHADOW		0.20


# define UC			unsigned char

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
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363

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

typedef	struct s_vertex t_vertex;
typedef struct s_cord   t_cord;
typedef struct s_rgb	t_rgb;
typedef struct s_irgb	t_irgb;
typedef struct s_all	t_all;
typedef struct s_objs	t_objs;

struct	s_vertex
{
	double	x;
	double	y;
	double	z;
};

struct	s_cord
{
	int		x;
	int 	y;
};

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	opacity;
}					t_rgb;

typedef struct		s_irgb
{
	int				r;
	int				g;
	int				b;
}					t_irgb;

typedef struct		s_ray{
	t_vertex		o;
	t_vertex		d;
	//double	 	magnitude;
}					t_ray;

typedef	struct		s_rt{
	double			t;
	double			brightness;
	t_vertex		norm;
	t_vertex		inter;
	t_rgb			rgb;
	int 			n;
	double			amb_int;
	double			dif_int;
	double			spc_int;
}					t_rt;

typedef struct		s_sphere{
	double			radius;
	double			r2;
	int 			n;
	t_vertex		center;
	t_rgb			color;
	double			amb_int;
	double			dif_int;
	double			spc_int;
}					t_sphere;

typedef struct		s_plane{
	t_ray			ray;
	t_rgb			color;
	int 			n;
	double			amb_int;
	double			dif_int;
	double			spc_int;
}					t_plane;

typedef struct		s_cylinder{
	t_ray			ray;
	double 			r;
	double 			r2;
	t_rgb 			color;
	int 			n;
	double			amb_int;
	double			dif_int;
	double			spc_int;
}					t_cylinder;


typedef struct		s_cone{
	t_ray			ray;
	t_rgb 			color;
	double 			alpha;
	double 			rad;
	double			cos2;
	double			sin2;
	int 			n;
	double			amb_int;
	double			dif_int;
	double			spc_int;
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

typedef struct 		s_flags{
	int 			redraw;
	int 			shadow;
	int				aliasing;
}					t_flags;

typedef struct		s_trans{
	double 			zoom;
	double 			shift;
}					t_trans;

typedef struct			s_calc{
	double				cos_x;
	double				sin_x;
	double				cos_y;
	double				sin_y;
	double				cos_z;
	double				sin_z;
}						t_calc;

typedef	struct		s_phong
{
	t_rgb			amb;
	t_rgb			dif;
	t_rgb			spc;
}					t_phong;

typedef	struct 		s_light{
	t_vertex		o;
//	double 			angle;
//	double 			power;
	struct s_light	*next;
}					t_light;


typedef struct		s_img{
	void			*img;
	char			*gda;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_mlx{
	void			*mlx;
	void			*wnd;
	t_img			img;
	t_img			img_a;
}					t_mlx;

typedef struct		s_objs{
	void			*obj;
	int 			(*ft_inter)(t_all*, t_ray*, t_objs*);
	void			(*ft_info)(t_all*, t_ray*, t_objs*);
	struct	s_objs	*next;
}					t_objs;

typedef struct		s_all{
	t_mlx			*mlx;
	t_dsp			dsp;
	t_objs			*scene;
	t_calc	 		calc;
	t_light 		*light;
	t_phong			phong;
	t_vertex		cam;
	t_rt			rt;
	t_trans			trans;
	t_flags			flags;
	int				x;
	int				y;
}					t_all;

void				init_all(t_all *all);
void				ft_create_obj_lst(t_all *all);
void				ft_create_light_lst(t_all *all);

int					ft_render(t_all *all);
t_phong				ft_phong(const t_rt *rt, t_rgb *color, t_light *light, t_vertex cam);t_rgb				ft_light_calc(t_all *all, t_rgb *color);

int					ft_key_hook(int keycode, t_all *all);

int					ft_mouse_hook(int key, int x, int y, t_all *all);
int 				ft_mouse_cord(int x, int y, t_all *all);

t_vertex			ft_sub_vector(t_vertex a, t_vertex b);
t_vertex			ft_sum_vector(t_vertex a, t_vertex b);
double				ft_dot_product(t_vertex a, t_vertex b);
t_vertex			ft_cross_vector(t_vertex a, t_vertex b);
double				ft_get_magnitude(t_vertex a);
t_vertex			ft_normalized_vector(t_vertex a);
t_vertex			ft_mult_vec_double(t_vertex a, double b);
t_vertex			ft_divide_vec_double(t_vertex a, double b);
double				ft_cos_vector(t_vertex u, t_vertex v);
t_vertex			ft_reverse_vector(t_vertex a);
t_vertex			ft_reflect_vector(t_vertex a, t_vertex b);


int					ft_sphere_intersect(t_all *all, t_ray *ray, t_objs *ptr);
int					ft_plane_intersect(t_all *all, t_ray *ray, t_objs *ptr);
int					ft_cylinder_intersect(t_all *all, t_ray *ray, t_objs *ptr);
int					ft_cone_intersect(t_all *all, t_ray *ray, t_objs *ptr);

void				ft_get_info_sphere(t_all *all, t_ray *ray, t_objs *ptr);
void				ft_get_info_plane(t_all *all, t_ray *ray, t_objs *ptr);
void				ft_get_info_cylinder(t_all *all, t_ray *ray, t_objs *ptr);
void				ft_get_info_cone(t_all *all, t_ray *ray, t_objs *ptr);

void				ft_get_norm_sphere(t_all *all, t_objs *ptr);

int					ft_shadow_ray(t_all *all, t_light *light);
void				ft_antialiasing(char *data_in, int n);

void				ft_error(int error);
int					ft_exit(void);

#endif