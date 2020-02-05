/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:40:03 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 19:05:22 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			back_to_menu(t_mlx *mlx)
{
	if (mlx->type == 1)
		return (0);
	mlx_destroy_image(mlx->mlx, mlx->img);
	create_menu(mlx);
	return (0);
}

int			on_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
