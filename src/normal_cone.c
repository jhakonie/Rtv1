/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:36:04 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 16:14:06 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	normal_cone(t_ray_trace *rt, t_object *obj)
{
	t_v3	hit;
	t_v3	hit_normal;
	t_v3	ray_to_obj;
	float	obj_to_hit_proj;

	ray_to_obj = vec_sub(rt->ray_start, obj->pos);
	vec_normalize(&obj->dir);
	obj_to_hit_proj = vec_dot(rt->ray_dir, obj->dir) * rt->near
		+ vec_dot(ray_to_obj, obj->dir);
	obj_to_hit_proj *= (1 + obj->ang * obj->ang);
	hit = vec_add(rt->ray_start, vec_multiply_f(rt->ray_dir, rt->near));
	hit_normal = vec_multiply_f(obj->dir, obj_to_hit_proj);
	hit_normal = vec_sub(vec_sub(hit, obj->pos), hit_normal);
	vec_normalize(&hit_normal);
	shadow_ray_trace(rt, hit, hit_normal, obj);
	return (rt_true);
}
