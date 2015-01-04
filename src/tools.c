/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 20:33:48 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/04 18:40:55 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_setColorRGB(t_color *c, char r, char g, char b)
{
	c->rgb[0] = b;
	c->rgb[1] = g;
	c->rgb[2] = r;
	c->rgb[3] = 0;
}

void	ft_put_pixel_to_img(t_buffer *buffer, int x, int y, int color)
{
	int			octet;
	int			position;

	octet = buffer->line_size / WIN_WIDTH;
	if (y > 0)
		y -= 1;
	position = (buffer->line_size * y) + (x * octet);
	if (ft_memcmp(buffer->data + position, &color, octet) != 0)
		ft_memcpy(buffer->data + position, &color, octet);
}

int		ft_HSLtoHex(int h, float s, float l)
{
	t_color		color;
	float		C;
	float		X;
	float		m;

	C = (1 - abs(2 * l - 1)) * s;
	X = C * (1 - abs((h / 60) % 2 - 1));
	m = l - C / 2;
	//printf("C = %f, X = %f, m = %f\n", C, X, m);
	if (h >= 0 && h < 60)
		ft_setColorRGB(&color, (C + m) * 255, (X + m) * 255, (0 + m) * 255);
	else if (h >= 60 && h < 120)
		ft_setColorRGB(&color, (X + m) * 255, (C + m) * 255, (0 + m) * 255);
	else if (h >= 120 && h < 180)
		ft_setColorRGB(&color, (0 + m) * 255, (C + m) * 255, (X + m) * 255);
	else if (h >= 180 && h < 240)
		ft_setColorRGB(&color, (0 + m) * 255, (X + m) * 255, (C + m) * 255);
	else if (h >= 240 && h < 300)
		ft_setColorRGB(&color, (X + m) * 255, (0 + m) * 255, (C + m) * 255);
	else if (h >= 300 && h < 360)
		ft_setColorRGB(&color, (C + m) * 255, (0 + m) * 255, (X + m) * 255);
	else
		ft_setColorRGB(&color, 255, 255, 255);
	return (color.color);
}
