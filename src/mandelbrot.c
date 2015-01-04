/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 17:42:47 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/05 00:21:50 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_iterate(int max_it, int x, int y)
{
	int						i;

	i = 0;
	while (i < max_it)
	{
		i++;

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
			i = ft_iterate(fl->max_it, (x - fl->offset.x) * fl->zoom, (y - fl->offset.y) * fl->zoom);
			//printf("i = %d (%d, %d): %#x\n", i, x, y ,ft_HSLtoHex(i, 1, 0.5));
			ft_put_pixel_to_img(&fl->buffer, x, y, ft_HSLtoHex(i % 360, 1, 0.5 * (i < fl->max_it)));
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
