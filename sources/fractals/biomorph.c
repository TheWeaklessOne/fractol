/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:56:21 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/28 13:56:22 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		formula_biomorph(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp	z;
	t_comp	c;
	t_comp	t;
	int		i;

	i = -1;
	z = screen_to_complex(x, y, v);
	c = v.mouse;
	while (z.r * z.r < 256 && z.i * z.i < 256 && ++i < v.iters)
	{
		t = z;
		z.r = pow(t.r, 4) + pow(t.i, 4) - 6 * t.r * t.r * t.i * t.i + c.r;
		z.i = 4 * pow(t.r, 3) * t.i - 4 * t.r * pow(t.i, 3);
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ? 0 : mlx->colour * i;
}

void		init_biomorph(t_mlx *mlx)
{
	mlx->view.xmin = -2.0f;
	mlx->view.xmax = 1.0f;
	mlx->view.ymin = -1.0f;
	mlx->view.ymax = 1.0f;
	mlx->view.offx = -1.9;
	mlx->view.offy = -1.5f;
	mlx->view.zoom = 2.55f;
	mlx->view.iters = 50;
}

void		create_biomorph(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 5;
	mlx->colour = PSY_C;
	init_biomorph(mlx);
	render_window(mlx);
}
