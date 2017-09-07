/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:46:25 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:47:02 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>

/*
** openCL
*/
#if __APLE__
# include <OpenCL/opencl.h>
#endif

# include <stdlib.h>
# include <assert.h>
# include <sys/stat.h>
# include <string.h>

/*
************************
*/

# define D_NAME		"Fractal"
# define D_WIDTH	800
# define D_HEIGHT	600
# define ITER       155
# define LEFT		1
# define RIGHT		0
# define DEAD		0
# define ALIVE		1
# define HIDE		2

typedef struct			s_mlx {
	void				*mlx;
	void				*wnd;
	void				*img;
	char				*gda;
	int					bpb;
	int					size_line;
	int					endian;
}						t_mlx;

//typedef struct			s_cl{
//	cl_uint				num_devices;
//	cl_device_id		*devices;
//	cl_kernel			kernel;
//	cl_command_queue	cmd_queue[16];
//	cl_context			context;
//	cl_int				err;
//}						t_cl;

typedef struct			s_rgb{
	int					red;
	int					green;
	int					blue;
}						t_rgb;

typedef struct			s_xy{
	int					x;
	int					y;
}						t_xy;

typedef struct			s_disp{
	double				d_width;
	double				d_height;
	double				half_w;
	double				half_h;
}						t_disp;

typedef struct			s_mandl{
	double				zx;
	double				zy;
}						t_mandl;

typedef struct			s_fract{
	double				c_re;
	double				c_im;
	double				step_x;
	double				step_y;
	double				re_max;
	double				re_min;
	double				im_max;
	double				im_min;
}						t_fract;

typedef	struct			s_trans{
	double				scale;
	double				shift_x;
	double				shift_y;
}						t_trans;

typedef	struct			s_fly{
	void				*laser;
	void				*enemy;
	int					pos_enemy;
	int					enemy_move;
	int					shot;
	int					cab;
	int					hp_enemy;
	int					status;
	int					time_exp;
}						t_fly;

typedef struct			s_anim{
	int					all;
	int					up;
	int					down;
	int					right;
	int					left;
	int					on_of;
	int					m_shift;
	int					sprite;
	int					help;
}						t_anim;

typedef struct			s_all{
	t_mlx				*mlx;
//	t_cl				cl;
	t_disp				disp;
	t_mandl				m;
	t_fract				jul;
	t_trans				trans;
	t_anim				anim;
	t_xy				xy;
	t_fly				fly;
	t_rgb				rgb;
	int					m_iter;
	void				*sprite;
	void				*help;
	char				*filename;
	size_t				buffer_size;
	double				sx;
	double				sy;
}						t_all;

/*
**GENERAL
*/

void					init_all(t_all *all, char *str);
int						create_img(t_all *all);
void					ft_put_color(t_all *all, int x, int y, int color);
void					serpinski(t_all *all);
void					ft_draw_space(t_all *all);
void					fern(t_all *all);

/*
**INIT
*/

void					init_mandelbrot(t_all *all);
void					init_julia(t_all *all);
void					init_bs(t_all *all);
void					init_newton(t_all *all);
void					init_mask(t_all *all);
void					init_sierpinski(t_all *all);
void					init_space(t_all *all);
void					ft_step(t_all *all);
void					init_fish(t_all *all);
void					init_fern(t_all *all);

/*
**CONTROL
*/

int						ft_key_hook(int keycode, t_all *all);
int						ft_mouse_hook(int button, int x, int y, t_all *all);
void					mouse_shift(t_all *all);
int						ft_mouse_cord(int x, int y, t_all *all);
void					ft_scale(t_all *all, double x, double y, double mult);
void					ft_swap_fractal(int keycode, t_all *all);
int						ft_exit(void);

/*
**ERROR
*/

void					ft_error(int error);
//void					check_succeeded(char *message, cl_int err);
void					ft_opencl(t_all *all);

/*
**OPENC
*/

//void					ftcl_get_device(t_all *all);
//cl_kernel				load_kernel_from_file(cl_context context,
//						const char *filename);
//char					*load_program_source(const char *filename);
//void					ftcl_put_argv(t_all *all,
//						cl_context context, cl_mem *image);
//void					ftcl_thread(t_all *all, cl_command_queue
//						*cmd_queue, cl_mem *image);
//void					ftcl_release(t_all *all, cl_context context,
//						cl_command_queue *cmd_queue, cl_mem *image);

/*
**BONUS
*/

void					the_game(t_all *all);
void					init_game(t_all *all);
void					ft_key_game(int keycode, t_all *all);

void					julia_new(t_all *all, double step_x, double step_y, double re_min, double im_min, double shift_x, double shift_y, int m_iter);

#endif
