/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:09:16 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 00:37:50 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	shadow_ray_intersect(t_ray_trace *rt, t_v3 hit,
	t_v3 hit_normal, size_t i)
{
	t_t2	result;
	size_t	j;
	float	hit_normal_dot_light_dir;

	hit_normal_dot_light_dir = vec_dot(hit_normal, rt->light_direction);
	j = 0;
	while (j < rt->objs_size)
	{
		rt->new_start = hit;
		rt->light_distance = sqrtf(
				vec_len_exp2(vec_sub(rt->lights[i].pos, hit)));
		if (hit_normal_dot_light_dir > 0)
		{
			if (rt->objs[j].intersect(rt->light_direction, rt->new_start,
					&rt->objs[j], &result))
			{
				if ((result.t0 <= rt->light_distance && result.t0 > 0)
					&& (result.t1 <= rt->light_distance && result.t1 > 0))
					rt->transmission = 0;
			}
		}
		j++;
	}
}
