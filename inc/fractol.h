/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:27:58 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/30 14:18:04 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

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
	t_buffer		buffer;
}					t_fractol;

/*
** Prototypes from "events.c"
*/

int					mouse_event();
int					keyboard_event();

#endif
