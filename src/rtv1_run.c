/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:22:59 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 18:14:57 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_window_event(t_rtv1 *rtv1)
{
	if (rtv1->event.window.event == SDL_WINDOWEVENT_EXPOSED)
	{
		draw_to_window(rtv1);
	}
}

static t_bool	zz_switch_scene(t_rtv1 *rtv1, unsigned char scene_nbr)
{
	unsigned int	nbr;

	nbr = (unsigned int)(scene_nbr - '0');
	scene_del(&rtv1->rt);
	if (!(set_scene(&rtv1->rt, nbr)))
		return (rt_false);
	return (rt_true);
}

static t_bool	zz_on_key(t_rtv1 *rtv1)
{
	if ((rtv1->event.key.keysym.sym >= SDLK_0
			&& rtv1->event.key.keysym.sym <= SDLK_9))
	{
		if (!(zz_switch_scene(rtv1, rtv1->event.key.keysym.sym)))
			return (rt_false);
	}
	return (rt_true);
}

static t_bool	zz_wait_event(t_rtv1 *rtv1)
{
	if (SDL_WaitEvent(&rtv1->event) != 0)
	{
		if (rtv1->event.type == SDL_QUIT)
		{
			rtv1->quit_as_expected = rt_true;
			return (rt_false);
		}
		else if (rtv1->event.type == SDL_KEYDOWN)
		{
			if (rtv1->event.key.keysym.sym == SDLK_ESCAPE)
			{
				rtv1->quit_as_expected = rt_true;
				return (rt_false);
			}
			else if (!(zz_on_key(rtv1)))
				return (rt_false);
			rtv1->draw = rt_true;
		}
		else if (rtv1->event.type == SDL_WINDOWEVENT)
			zz_window_event(rtv1);
	}
	return (rt_true);
}

t_bool	rtv1_run(t_rtv1 *rtv1)
{
	while (rtv1->run)
	{
		rtv1->run = zz_wait_event(rtv1);
		if (rtv1->draw)
		{
			draw(rtv1);
			draw_to_window(rtv1);
		}
	}
	if (!rtv1->quit_as_expected)
		return (rt_false);
	return (rt_true);
}
