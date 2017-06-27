#ifndef FDF_FDF_H
#define FDF_FDF_H

#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <pthread.h>

#define D_NAME 	"FDF"
#define D_WIDTH 1600
#define D_HEIGHT 1200
#define STD_COLOR 0x0bff00
#define THREAD_NUM 12

typedef struct 		s_rgb{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	opacity;
}					t_rgb;

typedef struct 		s_rgbm{
	char	red;
	char	green;
	char	blue;
	char	opacity;
}					t_rgbm;

typedef struct s_line_cord{
	int			x0;
	int			y0;
	int			z0;
	int			x1;
	int			y1;
	int			z1;
	int 		dx;
	int 		sx;
	int 		dy;
	int 		sy;
	int 		err_1;
	int 		err_2;
	int			iter;
	t_rgb		*color0;
	t_rgb		*color1;
}				t_line_cord;

typedef struct		s_point{
	int				x;
	int 			y;
	int 			z;
	t_rgb			*color;
}					t_point;

typedef struct 		s_xy{
	int 			x;
	int 			y;
}					t_xy;

typedef struct			s_shift{
	int					x_shift;
	int 				y_shift;
}						t_shift;

typedef struct			s_point_lst{
	t_point				point;
	struct s_point_lst	*next_x;
	struct s_point_lst	*next_y;
}						t_point_lst;

typedef struct	s_mlx{
	void 		*mlx;
	void 		*wnd;
	void		*img;
	char 		*gda;
	int 		*bpb;
	int 		*size_line;
	int 		endian;
}				t_mlx;

typedef struct	s_trans{
	t_shift 	shift;
	double 		scale;
	double 		angle_z;
	double 		angle_y;
	double 		angle_x;
	int 		deep_z;
	char		r_color;
	char		g_color;
	char		b_color;
}				t_trans;

typedef struct s_calc{
	double 		cos_x;
	double 		sin_x;
	double 		cos_y;
	double 		sin_y;
	double 		cos_z;
	double 		sin_z;
	double 		shift_w;
	double 		shift_h;
	double 		shift_x;
	double		shift_y;
}				t_calc;

typedef struct	s_anim{
	int			all;
	int			right;
	int			left;
	int			down;
	int			up;
	int			animation;
	int 		gradient;
	int 		on_of;
	int			sprite;
}				t_anim;

typedef struct s_pars{
	int 		fd;
	char 		*str;
	char		**split;
}				t_pars;

typedef struct	s_all {
	t_mlx		*mlx;
	t_point_lst *map;
	t_trans		trans;
	t_xy 		step;
	t_anim		anim;
	t_calc		*calc;
	t_point		xy;
	t_rgbm		grad;
	t_pars      pars;
	double 		width;
	double 		height;
	double		d_width;
	double 		d_height;
	double 		m_x_s_x;
	double 		m_y_s_y;
	double 		half_w;
	double 		half_h;
	int			max_depth;
	int 		min_depth;
	double		num_op;
	int 		thr_iter;
	char 		*map_name;
	void		*sprite;
}				t_all;

void				ft_parser(char **av, t_all *all);
int					ft_draw_map(t_all *all);
void				ft_draw_line(t_all *all, t_line_cord *cord);
void				put_pixel_img(t_all *all, int x, int y, t_rgb *color);
int					ft_key_hook(int keycode, t_all *all);
int					ft_mouse_hook(int button,int x,int y,t_all *all);
void				ft_calc_all(t_all *all);
void				free_split(char **split);
void				creat_and_draw(t_all *all, t_point_lst lst0, t_point_lst lst1);
t_line_cord			*ft_create_cord(t_all *all, t_point_lst lst0, t_point_lst lst1);
int					ft_mouse_cord( int x,int y, t_all *all);
/*
 * COLOR
 */
int					set_color(t_point_lst *ret, int color);
t_rgb				*get_rgb(t_point_lst *ret, int color);
int 				ft_strtol(char *split);
t_rgb				*ft_gradient(t_all *all, t_line_cord *cord);


/*
 * TRANSFORMATION
 * * * * * * * * *
 */
void				ft_mult_and_scale(const t_all *all, t_point_lst *lst0, t_point_lst *lst1,
					   t_line_cord *ret);
void				move_centr_scale(const t_all *all, t_line_cord *ret);
void				mouse_shift(t_all *all);
/*
 * Axis rotation
 */
void ft_ox(t_all *all, t_point_lst *lst0, t_point_lst *lst1, t_line_cord *ret);
void ft_oy(t_all *all, t_line_cord *ret);
void ft_oz(t_all *all, t_line_cord *ret);
int					create_img(t_all *all);
void				ft_error(int error);

/*
 * BONUS
 */
void				write_lst(t_all *all);
int					ft_draw_line_pp(t_all *all, t_line_cord *cord);
void				ft_name_map(t_all *all, char **av);
void				put_sprite(t_all *all);
void				switcher(int keycode, t_all *all);

#endif //FDF_FDF_H
