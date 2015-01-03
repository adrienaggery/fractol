/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 20:00:31 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/03 19:19:12 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fractol *fl)
{
	(void)button;
	(void)x;
	(void)y;
	(void)fl;
	return (0);
}

int		keyboard_event(int keycode, t_fractol *fl)
{
	(void)fl;
	if (keycode == KEYCODE_EXIT)
		exit(EXIT_SUCCESS);
	return (0);
}
