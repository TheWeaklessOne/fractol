/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:06:01 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 19:08:35 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <pthread.h>

# define WIDTH 1200
# define HEIGHT 800
# define THREADS 16

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ENTER 36
# define KEY_Z 6
# define KEY_X 7
# define KEY_SPACE 49
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_FIVE 23
# define KEY_SIX 22
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91

# define MENU_1_C 0x414280
# define MENU_1_C_H 0x635280
# define MENU_2_C 0x814140
# define MENU_2_C_H 0xA25140
# define MENU_3_C 0x666666
# define MENU_3_C_H 0x777777
# define MENU_4_C 0xD4C992
# define MENU_4_C_H 0xE5D992
# define MENU_5_C 0x428140
# define MENU_5_C_H 0x639140
# define MENU_6_C 0xC7933A
# define MENU_6_C_H 0xD8A33A
# define MENU_7_C 0x22D4C2
# define MENU_7_C_H 0x44E4C2

# define INF_C 0x445157

# define PSY_C 0x654321
# define RED_C 0x0A0505
# define GREEN_C 0x050A05
# define BLUE_C 0x05050A
# define GREY_C 0x666666
# define NEWT_C 0x050A0F
# define THORN_C 0x08ED55

typedef struct s_mlx	t_mlx;

typedef struct			s_comp
{
	double				r;
	double				i;
}						t_comp;

typedef struct			s_viewport
{
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	double				zoom;
	double				offx;
	double				offy;
	long				iters;
	t_comp				mouse;
}						t_viewport;

typedef struct			s_thread
{
	int					id;
	t_mlx				*mlx;
}						t_thread;

typedef struct			s_render
{
	pthread_t			threads[THREADS];
	t_thread			args[THREADS];
}						t_render;

struct					s_mlx
{
	int					first_colour;
	int					second_colour;
	int					third_colour;
	int					fourth_colour;
	int					fifth_colour;
	int					six_colour;
	int					seventh_colour;
	int					eighth_colour;
	int					button_index;
	void				*mlx;
	void				*win;
	void				*img;
	int					*p_img;
	int					bpp;
	int					line_s;
	int					endian;
	int					type;
	int					need_info;
	t_viewport			view;
	int					colour;
	int					colour_rand;
	int					mouse_lock;
	t_render			render;
};

int						mouse_move_hook(int x, int y, t_mlx *mlx);
int						mouse_click_hook(int button, int x, int y, t_mlx *mlx);
int						key_hook(int key, t_mlx *mlx);
int						key_fractal_rotation(int key, t_mlx *mlx);

void					click_menu_button(t_mlx *mlx);
void					pick_menu_button(t_mlx *mlx, int index);

void					create_mand(t_mlx *mlx);
void					create_burningship(t_mlx *mlx);
void					create_julia(t_mlx *mlx);
void					create_biomorph(t_mlx *mlx);
void					create_spider(t_mlx *mlx);
void					create_newton(t_mlx *mlx);
void					create_thorn(t_mlx *mlx);
void					create_random(t_mlx *mlx);

void					formula_biomorph(t_mlx *mlx, int x, int y,
										t_viewport v);
void					formula_mand(t_mlx *mlx, int x, int y, t_viewport v);
void					formula_burningship(t_mlx *mlx, int x, int y,
											t_viewport v);
void					formula_julia(t_mlx *mlx, int x, int y, t_viewport v);
void					formula_spider(t_mlx *mlx, int x, int y, t_viewport v);
void					formula_newton(t_mlx *mlx, int x, int y, t_viewport v);
void					formula_thorn(t_mlx *mlx, int x, int y, t_viewport v);
void					formula_random(t_mlx *mlx, int x, int y, t_viewport v);

int						render_menu(t_mlx *mlx);
void					create_menu(t_mlx *mlx);
int						mouse_rotate_menu_hook(int x, int y, t_mlx *mlx);
int						mouse_click_menu_hook(int button, int x, int y,
												t_mlx *mlx);
int						back_to_menu(t_mlx *mlx);
int						key_menu_hook(int key, t_mlx *mlx);

t_comp					screen_to_complex(int x, int y, t_viewport v);
int						render_window(t_mlx *mlx);
void					render_info(t_mlx *mlx);
void					*render_thread(void *m);

void					init_mand(t_mlx *mlx);
void					init(t_mlx *mlx);

int						on_close(t_mlx *mlx);
#endif
