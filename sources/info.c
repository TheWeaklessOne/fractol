/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:45 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 19:05:40 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		on_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 40, 590, INF_C,
			"ESC - close");
	mlx_string_put(mlx->mlx, mlx->win, 40, 620, INF_C,
			"Mouse left click - fractal lock");
	mlx_string_put(mlx->mlx, mlx->win, 40, 650, INF_C,
			"1-7 - colour pick");
	mlx_string_put(mlx->mlx, mlx->win, 40, 680, INF_C,
			"Arrow keys - move fractal");
	mlx_string_put(mlx->mlx, mlx->win, 40, 710, INF_C,
			"Space button or mouse right click - back to menu");
}

void		render_info(t_mlx *mlx)
{
	if (mlx->view.iters < 12)
		mlx->view.iters += 0;
	if (mlx->need_info)
	{
		if (mlx->type == 1)
		{
			mlx_string_put(mlx->mlx, mlx->win, 40, 650, INF_C,
					"ESC - close");
			mlx_string_put(mlx->mlx, mlx->win, 40, 680, INF_C,
					"Enter(return) or left mouse click - enter");
			mlx_string_put(mlx->mlx, mlx->win, 40, 710, INF_C,
					"Arrow keys or mouse - menu navigation");
		}
		else
			on_menu(mlx);
		mlx_string_put(mlx->mlx, mlx->win, 40, 740, INF_C, "X - close info");
	}
	else
		mlx_string_put(mlx->mlx, mlx->win, 40, 740, INF_C, "Z - open info");
}
