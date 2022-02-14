/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:37:13 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 18:10:47 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_pixel(t_p2 point, t_frame_buffer *fb, uint color)
{
	unsigned long	i;

	i = 4 * ((unsigned int)point.y * fb->width + (unsigned int)point.x);
	fb->data[i + 0] = (color >> 24) & 0xff;
	fb->data[i + 3] = (color >> 16) & 0xff;
	fb->data[i + 2] = (color >> 8) & 0xff;
	fb->data[i + 1] = (color >> 0) & 0xff;
}
