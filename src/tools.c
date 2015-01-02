/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 13:51:17 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/02 23:41:31 by aaggery          ###   ########.fr       */
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

int		ft_HSVtoHex(int h, float s, float v)
{
	int		t1;
	float	f;
	float	l;
	float 	m;
	float	n;

	t1 = (h / 60) % 6;
	f = h / 60 - t1;
	l = v * (1 - s);
	m = v * (1 - s * f);
	n = v * (1 - (1 - f) * s);
	if (t1 == 0)
		return ((v * 255) * (n * 255) * (l * 255));
	else if (t1 == 1)
		return ((m * 255) * (v * 255) * (l * 255));
	else if (t1 == 2)
		return ((l * 255) * (v * 255) * (n * 255));
	else if (t1 == 3)
		return ((l * 255) * (m * 255) * (v * 255));
	else if (t1 == 4)
		return ((n * 255) * (l * 255) * (v * 255));
	else if (t1 == 5)
		return ((v * 255) * (l * 255) * (m * 255));
	else
		return (0);
}
