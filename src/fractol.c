/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:35:20 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/30 14:16:53 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init(t_fractol fl)
{

}

static void		ft_check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error, please specify a fractal.", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_putendl_fd("Error, too much arguments.", 2);
		exit(EXIT_FAILURE);
	}
	if (!(ft_strequ("mandelbrot", argv[1]) || ft_strequ("julia", argv[1]) ||
				ft_strequ("3", argv[1])))
	{
		ft_putendl_fd("Error, plase specify a valid fractal: mandelbrot, julia or 3.", 2);
		exit(EXIT_FAILURE);
	}
}

int				main(int argc, char **argv)
{
	t_fractol	fl;

	ft_check_args(argc, argv);
	ft_init(&fl);
	mlx_key_hook(fl.win, keyboard_event, &fl);
	mlx_mouse_hook(fl.win, mouse_event, &fl);
	mlx_loop();
	return (0);
}
