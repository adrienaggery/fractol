/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 17:42:47 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/03 22:33:38 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_iterate(int max_it, t_imaginary_number p)
{
	int						i;
	t_imaginary_number		new;
	t_imaginary_number		old;

	i = 0;
	new.real = 0;
	new.imaginary = 0;
	while (i < max_it)
	{
		i++;
		old.real = new.real;
		old.imaginary = new.imaginary;
		new.real = old.real * old.real - old.imaginary * old.imaginary + p.real;
		new.imaginary = 2 * old.real * old.imaginary + p.imaginary;
		if ((new.real * new.real + new.imaginary * new.imaginary) > 4)
			break ;
	}
	return (i);
}

static void		ft_buff_image(t_fractol *fl)
{
	int						i;
	int						x;
	int						y;
	t_imaginary_number		p;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			p.real = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * fl->zoom * WIN_WIDTH) + fl->offset.x;
			p.imaginary = (y - WIN_HEIGHT / 2) / (0.5 * fl->zoom * WIN_HEIGHT) + fl->offset.y;
			i = ft_iterate(fl->max_it, p);
			printf("i = %d (%d, %d): %#x\n", i, x, y ,ft_HSLtoHex(i, 1, 0.5));
			ft_put_pixel_to_img(&fl->buffer, x, y, ft_HSLtoHex(i, 1, 0.5));
			x++;
		}
		y++;
	}
}

int				draw_mandelbrot(t_fractol *fl)
{
	ft_buff_image(fl);
	mlx_put_image_to_window(fl->mlx, fl->win, fl->buffer.img, 0, 0);
	printf("Image Buffed\n");

	return (0);
}
