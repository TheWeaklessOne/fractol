/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:39:33 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 16:39:35 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			init(t_mlx *mlx)
{
	mlx->need_info = 0;
	mlx->button_index = -1;
	mlx->mouse_lock = 0;
	mlx->colour_rand = ((rand() % 256) << 16) +
			((rand() % 256) << 8) + (rand() % 256);
}

int				init_threads(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = -1;
	r = &mlx->render;
	while (++i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		if (pthread_create(r->threads + i, NULL, render_thread, r->args + i))
			on_close(mlx);
	}
	while (i--)
		if (pthread_join(r->threads[i], NULL))
			on_close(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int				render_window(t_mlx *mlx)
{
	if (mlx->type == 1)
		render_menu(mlx);
	else
		init_threads(mlx);
	render_info(mlx);
	return (0);
}
