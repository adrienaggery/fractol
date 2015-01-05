/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 17:42:47 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/05 18:52:37 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_iterate(int max_it, t_float2d c)
{
	int						i;
	t_float2d				tmp;
	float					x;

	i = 0;
	tmp.x = 0;
	tmp.y = 0;
	while (i++ < max_it && (tmp.x * tmp.x + tmp.y * tmp.y) < 4)
	{
		x = tmp.x;
		tmp.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		tmp.y = (2 * x * tmp.y) + c.y;
	}
	return (i);
}

static void		ft_buff_image(t_fractol *fl)
{
	int						i;
	int						x;
	int						y;
	t_float2d				c;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c.x = (x - fl->offset.x) * (1 / fl->zoom);
			c.y = (y - fl->offset.y) * (1 / fl->zoom);
			i = ft_iterate(fl->max_it, c);
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
