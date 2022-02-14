/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:30:32 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 14:24:44 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	normal_plane(t_ray_trace *rt, t_object *obj)
{
	t_v3		hit;
	t_v3		hit_normal;

	vec_normalize(&rt->ray_dir);
	hit = vec_add(rt->ray_start, vec_multiply_f(rt->ray_dir, rt->near));
	vec_normalize(&obj->dir);
	hit_normal = obj->dir;
	vec_normalize(&hit_normal);
	if (vec_dot(rt->ray_dir, obj->dir) > 0)
		hit_normal = vec_negate(hit_normal);
	shadow_ray_trace(rt, hit, hit_normal, obj);
	return (rt_true);
}
