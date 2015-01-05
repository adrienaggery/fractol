/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:27:58 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/05 21:39:05 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include <stdio.h> // a virer

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define KEYCODE_EXIT 53
# define KEYCODE_ZOOM 1
# define KEYCODE_DEZOOM 2
# define KEYCODE_MOVEUP 126
# define KEYCODE_MOVEDOWN 125
# define KEYCODE_MOVELEFT 123
# define KEYCODE_MOVERIGHT 124

# define ZOOMSTEP 256

typedef union		u_color
{
	int				color;
	char			rgb[4];
}					t_color;

typedef struct		s_point2d
{
	int				x;
	int				y;
}					t_point2d;

typedef struct		s_float2d
{
	float			x;
	float			y;
}					t_float2d;

typedef struct		s_buffer
{
	void			*img;
	char			*data;
	int				bpp;
	int				line_size;
	int				endian;
}					t_buffer;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	char			*name;
	float			zoom;
	t_point2d		offset;
	int				max_it;
	t_buffer		buffer;
}					t_fractol;

/*
** Prototypes to draw fractals
*/

int					draw_mandelbrot(t_fractol *fl);

/*
** Prototypes from "events.c"
*/

int					mouse_event(int button, int x, int y, t_fractol *fl);
int					keyboard_event(int keycode, t_fractol *fl);

/*
** Prototypes from "tools.c"
*/

void				ft_put_pixel_to_img(t_buffer *buffer, int x, int y, int color);
int					ft_HSLtoHex(int h, float s, float l);

#endif
