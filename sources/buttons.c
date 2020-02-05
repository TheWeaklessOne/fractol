/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:37:24 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 16:37:29 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			click_menu_button(t_mlx *mlx)
{
	int index;

	index = mlx->button_index;
	index == 1 ? create_mand(mlx) : 0;
	index == 2 ? create_burningship(mlx) : 0;
	index == 3 ? create_spider(mlx) : 0;
	index == 4 ? create_newton(mlx) : 0;
	index == 5 ? create_julia(mlx) : 0;
	index == 6 ? create_biomorph(mlx) : 0;
	index == 7 ? create_thorn(mlx) : 0;
	index == 8 ? create_random(mlx) : 0;
}

void			colour_reset(t_mlx *mlx)
{
	mlx->first_colour = MENU_1_C;
	mlx->second_colour = MENU_2_C;
	mlx->third_colour = MENU_3_C;
	mlx->fourth_colour = MENU_4_C;
	mlx->fifth_colour = MENU_5_C;
	mlx->six_colour = MENU_6_C;
	mlx->seventh_colour = MENU_7_C;
	mlx->eighth_colour = mlx->colour_rand;
}

void			pick_menu_button(t_mlx *mlx, int index)
{
	if (index > 8 || index < 1)
	{
		mlx->button_index = (index > 8) ? index - 8 : index + 8;
		index = mlx->button_index;
	}
	colour_reset(mlx);
	index == 1 ? mlx->first_colour = MENU_1_C_H : 0;
	index == 2 ? mlx->second_colour = MENU_2_C_H : 0;
	index == 3 ? mlx->third_colour = MENU_3_C_H : 0;
	index == 4 ? mlx->fourth_colour = MENU_4_C_H : 0;
	index == 5 ? mlx->fifth_colour = MENU_5_C_H : 0;
	index == 6 ? mlx->six_colour = MENU_6_C_H : 0;
	index == 7 ? mlx->seventh_colour = MENU_7_C_H : 0;
	index == 8 ? mlx->eighth_colour += ((22 << 16) + (1 << 8)) : 0;
}
