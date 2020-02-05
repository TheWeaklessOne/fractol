/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:15:15 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/24 20:15:17 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			*render_thread(void *m)
{
	t_thread	*t;
	int			x;
	int			y;
	const int	thread_height = HEIGHT / THREADS;

	t = (t_thread *)m;
	y = thread_height * t->id - 1;
	while (++y < thread_height * (t->id + 1) && (x = -1))
		while (++x < WIDTH)
		{
			t->mlx->type == 2 ? formula_mand(t->mlx, x, y, t->mlx->view) : 0;
			t->mlx->type == 3 ? formula_julia(t->mlx, x, y, t->mlx->view) : 0;
			t->mlx->type == 4 ? formula_burningship(t->mlx, x, y, t->mlx->view)
								: 0;
			t->mlx->type == 5 ? formula_biomorph(t->mlx, x, y, t->mlx->view)
								: 0;
			t->mlx->type == 6 ? formula_spider(t->mlx, x, y, t->mlx->view) : 0;
			t->mlx->type == 7 ? formula_newton(t->mlx, x, y, t->mlx->view) : 0;
			t->mlx->type == 8 ? formula_thorn(t->mlx, x, y, t->mlx->view) : 0;
			t->mlx->type == 9 ? formula_random(t->mlx, x, y, t->mlx->view) : 0;
		}
	return (NULL);
}

t_comp			screen_to_complex(int x, int y, t_viewport v)
{
	t_comp		p;

	p.r = (((double)x / WIDTH) * (v.xmax - v.xmin)) * v.zoom
			+ v.xmin + v.offx;
	p.i = (((double)y / HEIGHT) * (v.ymax - v.ymin)) * v.zoom
			+ v.ymin + v.offy;
	return (p);
}
