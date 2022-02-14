/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:24:39 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 17:54:14 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "frame_buffer.h"

void	frame_buffer_del(t_frame_buffer *fb)
{
	free(fb->data);
	buffer_set(fb, sizeof(*fb), 0);
}
