/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:58:25 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/28 13:58:26 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		formula_random(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	int		i;

	z = screen_to_complex(x, y, v);
	c = v.mouse;
	i = -1;
	while (z.r * z.r + z.i * z.i < 256 && ++i < v.iters)
	{
		if (mlx->colour_rand % 2)
			temp.r = z.r * z.r - (z.i * z.i) + c.r;
		else
			temp.r = z.r * z.r + (z.i * z.i) + c.r;
		temp.i = z.r * z.i * ((mlx->colour_rand >> 5) % 10 + 2) / 2 + c.i;
		z = temp;
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ? 0 : mlx->colour * i;
}

void		init_random(t_mlx *mlx)
{
	mlx->view.xmin = -2.0f;
	mlx->view.xmax = 1.0f;
	mlx->view.ymin = -1.0f;
	mlx->view.ymax = 1.0f;
	mlx->view.offx = -0.88f;
	mlx->view.offy = -1.0f;
	mlx->view.zoom = 1.92f;
	mlx->view.iters = 50;
}

void		create_random(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 9;
	mlx->colour = mlx->colour_rand;
	mlx->colour_rand = ((rand() % 256) << 16) +
			((rand() % 256) << 8) + (rand() % 256);
	init_random(mlx);
	render_window(mlx);
}
