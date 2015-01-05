/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 20:00:31 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/05 21:47:04 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_call_draw(t_fractol *fl)
{
	if (ft_strequ("mandelbrot", fl->name))
		draw_mandelbrot(fl);
	else if (ft_strequ("julia", fl->name))
		draw_mandelbrot(fl);
	else if (ft_strequ("X", fl->name))
		draw_mandelbrot(fl);

}

int		mouse_event(int button, int x, int y, t_fractol *fl)
{
	printf("%d", button);
	if (button == KEYCODE_ZOOM)
	{
		fl->offset.x = x / fl->zoom;
		fl->offset.y = y / fl->zoom;
		fl->zoom *= 2;
	}
	else if (button == KEYCODE_DEZOOM)
	{
		fl->offset.x = x / fl->zoom;
		fl->offset.y = y / fl->zoom;
		fl->zoom /= 2;
	}
	ft_call_draw(fl);
	return (0);
}

int		keyboard_event(int keycode, t_fractol *fl)
{
	if (keycode == KEYCODE_EXIT)
		exit(EXIT_SUCCESS);
	else if (keycode == KEYCODE_MOVEUP)
		fl->offset.y -= 1 / fl->zoom;
	else if (keycode == KEYCODE_MOVEDOWN)
		fl->offset.y += 1 / fl->zoom;
	else if (keycode == KEYCODE_MOVELEFT)
		fl->offset.x -= 1 / fl->zoom;
	else if (keycode == KEYCODE_MOVERIGHT)
		fl->offset.x += 1 / fl->zoom;
	ft_call_draw(fl);
	return (0);
}
