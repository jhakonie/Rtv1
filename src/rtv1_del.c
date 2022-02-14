/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:35:27 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 17:35:28 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "rtv1.h"

void	rtv1_del(t_rtv1 *rtv1)
{
	scene_del(&rtv1->rt);
	free(rtv1->frame_buffer.data);
	SDL_DestroyTexture(rtv1->texture);
	SDL_DestroyRenderer(rtv1->renderer);
	SDL_DestroyWindow(rtv1->window);
	SDL_Quit();
}
