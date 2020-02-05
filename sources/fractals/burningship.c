/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:57:16 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/28 13:57:17 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		formula_burningship(t_mlx *mlx, int x, int y, t_viewport v)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	int		i;

	z = screen_to_complex(x, y, v);
	c = z;
	i = -1;
	while (z.r * z.r + z.i * z.i < 256 && ++i < v.iters)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z = temp;
	}
	mlx->p_img[x + y * WIDTH] = (i == mlx->view.iters) ? 0 : mlx->colour * i;
}

void		init_burningship(t_mlx *mlx)
{
	mlx->view.xmin = -2.0f;
	mlx->view.xmax = 1.0f;
	mlx->view.ymin = -1.0f;
	mlx->view.ymax = 1.0f;
	mlx->view.offx = -1.0f;
	mlx->view.offy = -1.0f;
	mlx->view.zoom = 1.6f;
	mlx->view.iters = 50;
}

void		create_burningship(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->type = 4;
	mlx->colour = RED_C;
	init_burningship(mlx);
	render_window(mlx);
}
