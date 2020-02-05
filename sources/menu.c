/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:47:03 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 16:47:04 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_click_menu_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 1)
		click_menu_button(mlx);
	return (render_window(mlx));
}

int			mouse_rotate_menu_hook(int x, int y, t_mlx *mlx)
{
	if (x < WIDTH * 0.25 && y < HEIGHT * 0.5)
		pick_menu_button(mlx, (mlx->button_index = 1));
	else if (x < WIDTH * 0.5 && y < HEIGHT * 0.5)
		pick_menu_button(mlx, (mlx->button_index = 2));
	else if (x < WIDTH * 0.75 && y < HEIGHT * 0.5)
		pick_menu_button(mlx, (mlx->button_index = 3));
	else if (y < HEIGHT * 0.5)
		pick_menu_button(mlx, (mlx->button_index = 4));
	else if (x < WIDTH * 0.25)
		pick_menu_button(mlx, (mlx->button_index = 5));
	else if (x < WIDTH * 0.5)
		pick_menu_button(mlx, (mlx->button_index = 6));
	else if (x < WIDTH * 0.75)
		pick_menu_button(mlx, (mlx->button_index = 7));
	else
		pick_menu_button(mlx, (mlx->button_index = 8));
	return (render_window(mlx));
}

void		create_menu(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->p_img = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_s, &mlx->endian);
	mlx->first_colour = MENU_1_C;
	mlx->second_colour = MENU_2_C;
	mlx->third_colour = MENU_3_C;
	mlx->fourth_colour = MENU_4_C;
	mlx->fifth_colour = MENU_5_C;
	mlx->six_colour = MENU_6_C;
	mlx->seventh_colour = MENU_7_C;
	mlx->eighth_colour = mlx->colour_rand;
	mlx->type = 1;
	render_window(mlx);
}

void		check_coord(t_mlx *mlx, int x, int y)
{
	if (x < WIDTH * 0.25 && y < HEIGHT * 0.5)
		mlx->p_img[x + y * WIDTH] = mlx->first_colour;
	else if (x == WIDTH * 0.25)
		mlx->p_img[x + y * WIDTH] = 0;
	else if (x < WIDTH * 0.5 && y < HEIGHT * 0.5)
		mlx->p_img[x + y * WIDTH] = mlx->second_colour;
	else if (x == WIDTH * 0.5)
		mlx->p_img[x + y * WIDTH] = 0;
	else if (x < WIDTH * 0.75 && y < HEIGHT * 0.5)
		mlx->p_img[x + y * WIDTH] = mlx->third_colour;
	else if (x == WIDTH * 0.75)
		mlx->p_img[x + y * WIDTH] = 0;
	else if (y == HEIGHT * 0.5)
		mlx->p_img[x + y * WIDTH] = 0;
	else if (y < HEIGHT * 0.5)
		mlx->p_img[x + y * WIDTH] = mlx->fourth_colour;
	else if (x < WIDTH * 0.25)
		mlx->p_img[x + y * WIDTH] = mlx->fifth_colour;
	else if (x < WIDTH * 0.5)
		mlx->p_img[x + y * WIDTH] = mlx->six_colour;
	else if (x < WIDTH * 0.75)
		mlx->p_img[x + y * WIDTH] = mlx->seventh_colour;
	else
		mlx->p_img[x + y * WIDTH] = mlx->eighth_colour;
}

int			render_menu(t_mlx *mlx)
{
	int			x;
	int			y;

	y = -1;
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
			check_coord(mlx, x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 100, HEIGHT / 2 - 210, 0, "Mandelbrot");
	mlx_string_put(mlx->mlx, mlx->win, 395, HEIGHT / 2 - 210, 0, "Burningship");
	mlx_string_put(mlx->mlx, mlx->win, 718, HEIGHT / 2 - 210, 0, "Spider");
	mlx_string_put(mlx->mlx, mlx->win, 1017, HEIGHT / 2 - 210, 0, "Newton");
	mlx_string_put(mlx->mlx, mlx->win, 110, HEIGHT / 2 + 210, 0, "Julia");
	mlx_string_put(mlx->mlx, mlx->win, 410, HEIGHT / 2 + 210, 0, "Biomporph");
	mlx_string_put(mlx->mlx, mlx->win, 725, HEIGHT / 2 + 210, 0, "Thorn");
	mlx_string_put(mlx->mlx, mlx->win, 1020, HEIGHT / 2 + 210, 0, "Random");
	return (0);
}
