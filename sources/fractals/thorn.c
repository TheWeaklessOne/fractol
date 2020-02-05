/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thorn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:58:21 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/28 13:58:22 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		formula_thorn(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	int		i;

	z = screen_to_complex(x, y, v);
	c = v.mouse;
	i = -1;
	while (z.r * z.r + z.i * z.i < 10000 && ++i < v.iters)
	{
		temp = z;
		z.r = temp.r / cos(temp.i) + c.r;
		z.i = temp.i / sin(temp.r) + c.i;
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ? 0 : mlx->colour * i;
}

void		init_thorn(t_mlx *mlx)
{
	mlx->view.xmin = -2.0f;
	mlx->view.xmax = 1.0f;
	mlx->view.ymin = -1.0f;
	mlx->view.ymax = 1.0f;
	mlx->view.offx = -1.1f;
	mlx->view.offy = -0.8f;
	mlx->view.zoom = 2.0f;
	mlx->view.iters = 50;
}

void		create_thorn(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 8;
	mlx->colour = THORN_C;
	init_thorn(mlx);
	render_window(mlx);
}
