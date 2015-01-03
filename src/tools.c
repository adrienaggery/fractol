/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 20:33:48 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/03 22:34:33 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	float		C;
	float		X;
	float		m;

	C = (1 - abs(2 * l - 1)) * s;
	X = C * (1 - abs((h / 60) % 2 - 1));
	m = l - C / 2;
	//printf("C = %f, X = %f, m = %f\n", C, X, m);
	if (h >= 0 && h < 60)
		return (((C + m) * 255 + 1) * ((X + m) * 255 + 1) * ((0 + m) * 255 + 1));
	else if (h >= 60 && h < 120)
		return (((X + m) * 255 + 1) * ((C + m) * 255 + 1) * ((0 + m) * 255 + 1));
	else if (h >= 120 && h < 180)
		return (((0 + m) * 255 + 1) * ((C + m) * 255 + 1) * ((X + m) * 255 + 1));
	else if (h >= 180 && h < 240)
		return ((0 + m) * (X + m) * (C + m));
	else if (h >= 240 && h < 300)
		return ((X + m) * (0 + m) * (C + m));
	else if (h >= 300 && h < 360)
		return ((C + m) * (0 + m) * (X + m));
	else
		return (0);
}
