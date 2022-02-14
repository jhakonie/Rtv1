/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:40:28 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 21:35:02 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
*         . ----------- .
*      (      H * .        )
*      |  ' ----|----'-- ' |   P-C = (Q-C)^2 + r^2
*      |        |     |    |   Q-C = (P-C) . dir | (direction of cylinder)
*      |        |     |    |     -> using projection of P-C on C-H
*      |        |_____* P  |   (P-C)^2 - [(P-C) . dir]^2 = r^2
*      |        |    /|    |   P = O + t * raydir
*      |        |   / |    |     -> replace P with this on the above equation
*      |        |  /  |    |   (O+t*raydir-C)^2 - [(O+t*raydir).dir]^2 = r^2
*      |        | /   |    |     -> solve for t
*      |  . ----|---- | .  |     -> O-C = w;
*      (     C  ' r.  |    )   a = raydir.raydir - raydir.dir * raydir.dir
*         ' ----------*  '     b = 2 * [(w.raydir) - (v.dir)(v.dir)]
*                              c = (w.w) - (v.dir)^2 - r^2
*/

t_bool	intersect_cylinder(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
	t_t2 *result)
{
	t_quadratic_solve	qs;
	t_v3				ray_to_obj;

	vec_normalize(&obj->dir);
	ray_to_obj = vec_sub(ray_start, obj->pos);
	qs.a = vec_dot(ray_dir, ray_dir)
		- vec_dot(ray_dir, obj->dir) * vec_dot(ray_dir, obj->dir);
	qs.b = 2 * (vec_dot(ray_to_obj, ray_dir)
			- vec_dot(ray_dir, obj->dir) * vec_dot(ray_to_obj, obj->dir));
	qs.c = vec_dot(ray_to_obj, ray_to_obj) - vec_dot(ray_to_obj, obj->dir)
		* vec_dot(ray_to_obj, obj->dir) - obj->radius * obj->radius;
	qs.discriminant = qs.b * qs.b - 4 * (qs.a * qs.c);
	qs.numerator = 2 * qs.a;
	if (qs.discriminant < 0 || qs.numerator == 0
		|| fabsf(qs.discriminant) < 0.001f)
		return (rt_false);
	result->t0 = (-qs.b - sqrtf(qs.discriminant)) / qs.numerator;
	result->t1 = (-qs.b + sqrtf(qs.discriminant)) / qs.numerator;
	return (rt_true);
}
