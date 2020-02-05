/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:13:41 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/24 20:13:42 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_fractal_colour_pick(int key, t_mlx *mlx)
{
	if (key == KEY_ONE || key == KEY_1)
		mlx->colour = BLUE_C;
	else if (key == KEY_TWO || key == KEY_2)
		mlx->colour = GREEN_C;
	else if (key == KEY_THREE || key == KEY_3)
		mlx->colour = RED_C;
	else if (key == KEY_FOUR || key == KEY_4)
		mlx->colour = PSY_C;
	else if (key == KEY_FIVE || key == KEY_5)
		mlx->colour = GREY_C;
	else if (key == KEY_SIX || key == KEY_6)
		mlx->colour = NEWT_C;
	else if (key == KEY_SEVEN || key == KEY_7)
		mlx->colour = THORN_C;
	else if (key == KEY_EIGHT || key == KEY_8)
	{
		mlx->colour_rand = ((rand() % 256) << 16) +
				((rand() % 256) << 8) + (rand() % 256);
		mlx->colour = mlx->colour_rand;
	}
	return (render_window(mlx));
}

int			key_fractal_rotation(int key, t_mlx *mlx)
{
	if (key == KEY_RIGHT)
		mlx->view.offx -= (mlx->view.xmax - mlx->view.xmin) *
				mlx->view.zoom * 0.0025f;
	else if (key == KEY_LEFT)
		mlx->view.offx += (mlx->view.xmax - mlx->view.xmin) *
				mlx->view.zoom * 0.0025f;
	else if (key == KEY_UP)
		mlx->view.offy += (mlx->view.ymax - mlx->view.ymin) *
				mlx->view.zoom * 0.0025f;
	else if (key == KEY_DOWN)
		mlx->view.offy -= (mlx->view.ymax - mlx->view.ymin) *
				mlx->view.zoom * 0.0025f;
	else if (key == KEY_SPACE)
		return (back_to_menu(mlx));
	else
		return (key_fractal_colour_pick(key, mlx));
	return (render_window(mlx));
}

int			key_menu_hook(int key, t_mlx *mlx)
{
	if (key == KEY_RIGHT)
		pick_menu_button(mlx, (++mlx->button_index));
	else if (key == KEY_LEFT)
		pick_menu_button(mlx, (--mlx->button_index));
	else if (key == KEY_UP)
		pick_menu_button(mlx, (mlx->button_index -= 4));
	else if (key == KEY_DOWN)
		pick_menu_button(mlx, (mlx->button_index += 4));
	else if (key == KEY_ENTER)
		click_menu_button(mlx);
	return (render_window(mlx));
}
