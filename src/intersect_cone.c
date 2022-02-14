/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:01:53 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 19:32:05 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	intersect_cone(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
	t_t2 *result)
{
	t_quadratic_solve	qs;
	float				cone_factor;
	t_v3				start_sub_obj;

	vec_normalize(&obj->dir);
	cone_factor = (1 + obj->ang * obj->ang);
	start_sub_obj = vec_sub(ray_start, obj->pos);
	qs.a = vec_dot(ray_dir, ray_dir) - cone_factor
		* vec_dot(ray_dir, obj->dir) * vec_dot(ray_dir, obj->dir);
	qs.b = 2 * (vec_dot(start_sub_obj, ray_dir)
			- cone_factor * vec_dot(ray_dir, obj->dir)
			* vec_dot(start_sub_obj, obj->dir));
	qs.c = vec_dot(start_sub_obj, start_sub_obj) - cone_factor
		* vec_dot(start_sub_obj, obj->dir) * vec_dot(start_sub_obj, obj->dir)
		- obj->radius * obj->radius;
	qs.discriminant = qs.b * qs.b - 4 * qs.a * qs.c;
	qs.numerator = 2 * qs.a;
	if (qs.discriminant < 0 || qs.numerator == 0
		|| fabsf(qs.discriminant) < 0.001f)
		return (rt_false);
	result->t0 = (-qs.b - sqrtf(qs.discriminant)) / qs.numerator;
	result->t1 = (-qs.b + sqrtf(qs.discriminant)) / qs.numerator;
	return (rt_true);
}
