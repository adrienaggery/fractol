/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:35:20 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/04 19:11:46 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init(t_fractol *fl, char **argv)
{
	fl->name = argv[1];
	fl->max_it = 128;
	fl->zoom = 1;
	fl->offset.x = 0;
	fl->offset.y = 0;
	fl->mlx = mlx_init();
	if (fl->mlx == NULL)
	{
		ft_putendl_fd("Error, failed to initiate mlx.", 2);
		exit(EXIT_FAILURE);
	}
	fl->win = mlx_new_window(fl->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (ft_strequ("mandelbrot", argv[1]))
		mlx_expose_hook(fl->win, draw_mandelbrot, fl);
	else if (ft_strequ("julia", argv[1]))
		mlx_expose_hook(fl->win, draw_mandelbrot, fl);
	else if (ft_strequ("X", argv[1]))
		mlx_expose_hook(fl->win, draw_mandelbrot, fl);
	fl->buffer.img = mlx_new_image(fl->mlx, WIN_WIDTH, WIN_HEIGHT);
	fl->buffer.data = mlx_get_data_addr(fl->buffer.img, &fl->buffer.bpp,
			&fl->buffer.line_size, &fl->buffer.endian);

}

static void		ft_check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error, please specify a fractal: mandelbrot, julia or X.", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_putendl_fd("Error, please specify a valid fractal: mandelbrot, julia or X.", 2);
		exit(EXIT_FAILURE);
	}
	if (!(ft_strequ("mandelbrot", argv[1]) || ft_strequ("julia", argv[1]) ||
				ft_strequ("X", argv[1])))
	{
		ft_putendl_fd("Error, plase specify a valid fractal: mandelbrot, julia or X.", 2);
		exit(EXIT_FAILURE);
	}
}

int				main(int argc, char **argv)
{
	t_fractol	fl;

	ft_check_args(argc, argv);
	ft_init(&fl, argv);
	mlx_key_hook(fl.win, keyboard_event, &fl);
	mlx_mouse_hook(fl.win, mouse_event, &fl);
	mlx_loop(fl.mlx);
	return (0);
}
