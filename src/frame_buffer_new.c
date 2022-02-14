/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:10:31 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 18:14:52 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "frame_buffer.h"

t_bool	frame_buffer_new(t_frame_buffer *fb, unsigned int image_width,
	unsigned int image_height)
{
	fb->data_size = image_width * image_height * 4;
	fb->data = (unsigned char *)malloc(fb->data_size);
	if (!fb->data)
		return (rt_false);
	buffer_set(fb->data, fb->data_size, 0);
	fb->width = image_width;
	fb->height = image_height;
	return (rt_true);
}
