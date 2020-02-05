/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:40:36 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 16:40:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void			formula_mand(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp		z;
	t_comp		c;
	t_comp		t;
	int			i;

	i = -1;
	z = screen_to_complex(x, y, v);
	c = z;
	while (z.r * z.r + z.i * z.i < 256 && ++i < v.iters)
	{
		t.r = z.r * z.r - z.i * z.i + c.r;
		t.i = z.r * z.i * 2 + c.i;
		z = t;
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ? 0 : mlx->colour * i;
}

void			init_mand(t_mlx *mlx)
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

void			create_mand(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 2;
	mlx->colour = BLUE_C;
	init_mand(mlx);
	render_window(mlx);
}
