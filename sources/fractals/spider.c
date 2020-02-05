/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:58:17 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/28 13:58:18 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		formula_spider(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp	z;
	t_comp	c;
	t_comp	tz;
	t_comp	tc;
	int		i;

	i = -1;
	z = screen_to_complex(x, y, v);
	c = z;
	while ((z.r * z.r + z.i * z.i) < 256 && ++i < v.iters)
	{
		tz = z;
		tc = c;
		z.r = tz.r * tz.r - tz.i * tz.i + c.r;
		z.i = 2 * tz.r * tz.i + tc.i;
		c.r = tc.r / 2 + z.r;
		c.i = tc.i / 2 + z.i;
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ? 0 : mlx->colour * i;
}

void		init_spider(t_mlx *mlx)
{
	mlx->view.xmin = -2.0f;
	mlx->view.xmax = 1.0f;
	mlx->view.ymin = -1.0f;
	mlx->view.ymax = 1.0f;
	mlx->view.offx = -1.8f;
	mlx->view.offy = -1.2f;
	mlx->view.zoom = 2.2f;
	mlx->view.iters = 50;
}

void		create_spider(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 6;
	mlx->colour = GREY_C;
	init_spider(mlx);
	render_window(mlx);
}
