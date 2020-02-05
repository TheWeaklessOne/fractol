/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:00 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 16:38:02 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom(int x, int y, t_viewport *v, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / WIDTH) * (nw - w);
	v->offy -= ((double)y / HEIGHT) * (nh - h);
}

int			key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		return (on_close(mlx));
	else if (key == KEY_Z)
		mlx->need_info = 1;
	else if (key == KEY_X)
		mlx->need_info = 0;
	else if (mlx->type == 1)
		return (key_menu_hook(key, mlx));
	else
		return (key_fractal_rotation(key, mlx));
	return (render_window(mlx));
}

int			mouse_move_hook(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (mlx->type == 1)
			return (mouse_rotate_menu_hook(x, y, mlx));
		if (!mlx->mouse_lock)
			mlx->view.mouse = screen_to_complex(x, y, mlx->view);
		render_window(mlx);
	}
	return (0);
}

int			mouse_click_hook(int button, int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (button == 1)
		{
			if (mlx->type == 1)
				return (mouse_click_menu_hook(button, x, y, mlx));
			mlx->mouse_lock = !mlx->mouse_lock;
		}
		else if (button == 2 && mlx->type != 1)
			return (back_to_menu(mlx));
		else if (button == 4 && mlx->type != 1)
		{
			zoom(x, y, &mlx->view, 1 / 0.95f);
			mlx->view.iters -= mlx->view.iters < 10 ? 0 : 1;
		}
		else if (button == 5 && mlx->type != 1)
		{
			zoom(x, y, &mlx->view, 0.95f);
			mlx->view.iters += mlx->view.zoom < 9 ? 1 : 0;
		}
		render_window(mlx);
	}
	return (0);
}
