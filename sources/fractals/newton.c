/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:58:13 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/28 13:58:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void			formula_newton(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp		z;
	t_comp		c;
	t_comp		t;
	double		res;
	int			i;

	i = -1;
	z = screen_to_complex(x, y, v);
	c = z;
	while ((z.r * z.r + z.i * z.i) < 512 && ++i < v.iters)
	{
		t = z;
		res = (t.r * t.r + t.i * t.i) * (t.r * t.r + t.i * t.i);
		z.r = (double)2 / 3 * t.r + (t.r * t.r - t.i * t.i) / 3 / res;
		z.i = (double)2 / 3 * t.i * (1 - t.r / res);
		c.r = t.r - z.r;
		c.i = t.i - z.i;
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ?
			0 : mlx->colour * i * 100;
}

void			init_newton(t_mlx *mlx)
{
	mlx->view.xmin = -2.0f;
	mlx->view.xmax = 1.0f;
	mlx->view.ymin = -1.0f;
	mlx->view.ymax = 1.0f;
	mlx->view.offx = -1.0f;
	mlx->view.offy = -0.5f;
	mlx->view.zoom = 1.5f;
	mlx->view.iters = 50;
}

void			create_newton(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 7;
	mlx->colour = NEWT_C;
	init_newton(mlx);
	render_window(mlx);
}
