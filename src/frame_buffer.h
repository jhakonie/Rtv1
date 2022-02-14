/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:27:52 by jsankari          #+#    #+#             */
/*   Updated: 2022/02/12 23:38:37 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_BUFFER_H
# define FRAME_BUFFER_H

# include "types.h"

struct	s_frame_buffer
{
	unsigned char		*data;
	unsigned long int	data_size;
	unsigned int		width;
	unsigned int		height;
};
typedef struct s_frame_buffer	t_frame_buffer;

t_bool	frame_buffer_new(t_frame_buffer *fb, unsigned int image_width,
			unsigned int image_height);
void	frame_buffer_del(t_frame_buffer *fb);
void	frame_buffer_set(t_frame_buffer *fb, float x, float y,
			unsigned int abgr);

#endif
