/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:42 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/22 17:09:24 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					ft_strcmp(const char *s11, const char *s22)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)s11;
	s2 = (unsigned char*)s22;
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

int					check_args(const char *argv)
{
	if (!ft_strcmp(argv, "menu"))
		return (1);
	else if (!ft_strcmp(argv, "mandelbrot"))
		return (2);
	else if (!ft_strcmp(argv, "julia"))
		return (3);
	else if (!ft_strcmp(argv, "burningship"))
		return (4);
	else if (!ft_strcmp(argv, "biomorph"))
		return (5);
	else if (!ft_strcmp(argv, "spider"))
		return (6);
	else if (!ft_strcmp(argv, "newton"))
		return (7);
	else if (!ft_strcmp(argv, "thorn"))
		return (8);
	else if (!ft_strcmp(argv, "random"))
		return (9);
	return (0);
}

void				set_up_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, (1L << 0), key_hook, mlx);
	mlx_hook(mlx->win, 4, (1L << 2), mouse_click_hook, mlx);
	mlx_hook(mlx->win, 6, (1L << 13), mouse_move_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, on_close, mlx);
}

void				put_usage(void)
{
	write(1, "\nUsage: ./fractol *fractal types* \n"
	"Available types:\nmandelbrot;\njulia;\nburningship;\nbiomorph;\n"
	"spider;\nnewton;\nthorn;\nrandom.\n\n"
	"Or ./fractol menu\n", 144);
}

int					main(int argc, char *argv[])
{
	t_mlx			mlx;

	if (argc == 2 && (mlx.type = check_args(argv[1])))
	{
		if ((mlx.mlx = mlx_init()))
			if ((mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fractol")))
			{
				init(&mlx);
				set_up_hooks(&mlx);
				mlx.type == 1 ? create_menu(&mlx) : 0;
				mlx.type == 2 ? create_mand(&mlx) : 0;
				mlx.type == 3 ? create_julia(&mlx) : 0;
				mlx.type == 4 ? create_burningship(&mlx) : 0;
				mlx.type == 5 ? create_biomorph(&mlx) : 0;
				mlx.type == 6 ? create_spider(&mlx) : 0;
				mlx.type == 7 ? create_newton(&mlx) : 0;
				mlx.type == 8 ? create_thorn(&mlx) : 0;
				mlx.type == 9 ? create_random(&mlx) : 0;
				mlx_loop(mlx.mlx);
			}
	}
	else
		put_usage();
	return (0);
}
