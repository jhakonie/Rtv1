/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:06:23 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 17:26:53 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	shadow_ray_trace(t_ray_trace *rt, t_v3 hit, t_v3 hit_normal,
	t_object *obj)
{
	size_t	i;
	float	intensity;

	rt->final_color = obj->color;
	intensity = rt->ambient;
	i = 0;
	while (i < rt->lights_size)
	{
		rt->light_direction = vec_sub(rt->lights[i].pos, hit);
		vec_normalize(&rt->light_direction);
		rt->transmission = 1;
		shadow_ray_intersect(rt, hit, hit_normal, i);
		if (vec_dot(hit_normal, rt->light_direction) > 0)
		{
			intensity += rt->lights[i].intensity * rt->transmission
				* vec_dot(hit_normal, rt->light_direction);
		}
		rt->transmission = 1;
		i++;
	}
	light_pixel(&rt->final_color, intensity);
	return (rt_true);
}
