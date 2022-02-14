/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:19:47 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 16:45:12 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_ray_create(t_ray_trace *rt, uint x, uint y, t_frame_buffer *fb)
{
	vec_normalize(&rt->cam.up_dir);
	vec_normalize(&rt->cam.dir);
	rt->ray_dir = vec_sub(rt->proj_plane_center,
			vec_multiply_f(rt->cam.side_dir, (x - fb->width * 0.5f + 0.5f)));
	rt->cam.up_dir = vec_cross(rt->cam.side_dir, rt->cam.dir);
	rt->ray_dir = vec_add(rt->ray_dir,
			vec_multiply_f(rt->cam.up_dir, (y - fb->height * 0.5f + 0.5f)));
	rt->ray_dir = vec_sub(rt->ray_dir, rt->ray_start);
	vec_normalize(&rt->ray_dir);
	rt->final_color = 0;
}

void	draw(t_rtv1 *rtv1)
{
	uint	x;
	uint	y;

	rtv1->rt.proj_plane_center = vec_add(rtv1->rt.cam.pos,
			vec_multiply_f(rtv1->rt.cam.dir, rtv1->rt.proj_plane_dist));
	buffer_set(rtv1->frame_buffer.data, rtv1->frame_buffer.data_size, 0);
	y = 0;
	while (y < rtv1->frame_buffer.height)
	{
		x = 0;
		while (x < rtv1->frame_buffer.width)
		{
			zz_ray_create(&rtv1->rt, x, y, &rtv1->frame_buffer);
			if (ray_trace(&rtv1->rt))
				draw_pixel((t_p2){x, y},
					&rtv1->frame_buffer, rtv1->rt.final_color);
			rtv1->rt.final_color = 0;
			x++;
		}
		y++;
	}
	rtv1->draw = rt_false;
}
