/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:22:22 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 21:17:25 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_bool	zz_on_error(t_rtv1 *rtv1, unsigned char i)
{
	if (i > 4)
		frame_buffer_del(&rtv1->frame_buffer);
	if (i > 3)
		SDL_DestroyTexture(rtv1->texture);
	if (i > 2)
		SDL_DestroyRenderer(rtv1->renderer);
	if (i > 1)
		SDL_DestroyWindow(rtv1->window);
	if (i > 0)
		SDL_Quit();
	return (rt_false);
}

static t_bool	zz_sdl(t_rtv1 *rtv1, unsigned int window_width,
	unsigned int window_height)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		return (zz_on_error(rtv1, 0));
	rtv1->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, window_width, window_height, 0);
	if (!rtv1->window)
		return (zz_on_error(rtv1, 1));
	rtv1->renderer = SDL_CreateRenderer(rtv1->window, -1, 0);
	if (!(rtv1->renderer))
		return (zz_on_error(rtv1, 2));
	rtv1->texture = SDL_CreateTexture(rtv1->renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, window_width, window_height);
	if (!rtv1->texture)
		return (zz_on_error(rtv1, 3));
	return (rt_true);
}

t_bool	rtv1_new(t_rtv1 *rtv1, unsigned int window_width,
	unsigned int window_height)
{
	if (!zz_sdl(rtv1, window_width, window_height))
		return (rt_false);
	if (!frame_buffer_new(&rtv1->frame_buffer, window_width, window_height))
		return (zz_on_error(rtv1, 4));
	if (rtv1->rt.scene)
	{
		if (!scene_new(&rtv1->rt))
			return (zz_on_error(rtv1, 5));
	}
	else
	{
		if (!(set_scene(&rtv1->rt, 1)))
			return (zz_on_error(rtv1, 5));
	}
	rtv1->run = rt_true;
	rtv1->quit_as_expected = rt_false;
	rtv1->draw = rt_true;
	return (rt_true);
}
