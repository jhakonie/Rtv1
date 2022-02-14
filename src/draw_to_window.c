/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:25:41 by jsankari          #+#    #+#             */
/*   Updated: 2022/02/13 21:22:26 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_to_window(t_rtv1 *rtv1)
{
	int	*texture_data;
	int	texture_pitch;

	if (SDL_LockTexture(rtv1->texture, NULL, (void **)&texture_data,
			&texture_pitch) < 0)
	{
		rtv1->run = rt_false;
	}
	buffer_copy(texture_data, rtv1->frame_buffer.data,
		rtv1->frame_buffer.data_size);
	SDL_UnlockTexture(rtv1->texture);
	if (SDL_RenderCopy(rtv1->renderer, rtv1->texture, NULL, NULL) < 0)
	{
		rtv1->run = rt_false;
	}
	SDL_RenderPresent(rtv1->renderer);
}
