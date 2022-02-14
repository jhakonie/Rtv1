/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:28:47 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 00:25:06 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	normal_sphere(t_ray_trace *rt, t_object *obj)
{
	t_v3	hit;
	t_v3	hit_normal;

	hit = vec_add(rt->ray_start, vec_multiply_f(rt->ray_dir, rt->near));
	hit_normal = vec_sub(hit, obj->pos);
	vec_normalize(&hit_normal);
	if (vec_dot(rt->ray_dir, hit_normal) > 0)
		hit_normal = vec_negate(hit_normal);
	shadow_ray_trace(rt, hit, hit_normal, obj);
	return (rt_true);
}
