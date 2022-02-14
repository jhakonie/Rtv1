/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:10:40 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 19:38:59 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame_buffer.h"

void	frame_buffer_set(t_frame_buffer *fb, float x, float y,
	unsigned int abgr)
{
	unsigned long	i;

	i = 4 * ((unsigned int)y * fb->width + (unsigned int)x);
	fb->data[i + 0] = (abgr >> 24) & 0xff;
	fb->data[i + 1] = (abgr >> 16) & 0xff;
	fb->data[i + 2] = (abgr >> 8) & 0xff;
	fb->data[i + 3] = (abgr >> 0) & 0xff;
}
