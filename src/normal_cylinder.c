/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:34:35 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 00:31:22 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
* ray_to_obj = the vector from ray/camera origin to object center.
* obj_to_hit_proj = projection of the vector from object center to hit on
* 					object direction.
*
*         . ----------- .
*      (      H * .        )  M = C + obj_to_hit_proj * dir
*      |  ' ----|---'--- ' |  To get obj_to_hit_proj the projection of
*      |        |     |    |  RP on CH is added to the projection of
*      |        |  N  |    |  RC on CH
*      |     M  *-----* P  |
*      |        |    /| \  |  Projection of RP to CH = RP . (normalized)CH
*      |        |   / |  \ |  Projection of RC to CH = RC . (normalized)CH
*      |        |  /  |   \|
*      |      C | /   |    |.
*      |  . ----*---- | .  | \
*      (        ' r.  |    )  * R
*         ' ----------*  '
*/

t_bool	normal_cylinder(t_ray_trace *rt, t_object *obj)
{
	t_v3	hit;
	t_v3	hit_normal;
	t_v3	ray_to_obj;
	float	obj_to_hit_proj;

	vec_normalize(&obj->dir);
	ray_to_obj = vec_sub(rt->ray_start, obj->pos);
	vec_normalize(&obj->dir);
	obj_to_hit_proj = vec_dot(rt->ray_dir, obj->dir) * rt->near
		+ vec_dot(ray_to_obj, obj->dir);
	hit = vec_add(rt->ray_start, vec_multiply_f(rt->ray_dir, rt->near));
	hit_normal = vec_sub(vec_sub(hit, obj->pos),
			vec_multiply_f(obj->dir, obj_to_hit_proj));
	vec_normalize(&hit_normal);
	if (vec_dot(rt->ray_dir, hit_normal) > 0)
		hit_normal = vec_negate(hit_normal);
	shadow_ray_trace(rt, hit, hit_normal, obj);
	return (rt_true);
}
