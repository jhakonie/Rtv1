/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:08:45 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 20:22:50 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/* 
** Ro = ray origin
** Rd = ray direction
** s = sphere center
** ray_to_obj = s - Ro
** t = point, where ray hits the sphere. s-Ro * Rd
** y = s - t
** y2 = ray_to_obj length squared (hypotenusa)
**   -   t squared (side)
** x = can be solved from y and sphere radius with phytagorean
** theroem. 
**           _________
**        /            \
**       /               \
**      |        s        |
**      |        *        |
**      |        | y      |
**  Ro __t0______*t____t1/____ ray
**        \  x          /
**           --------- 
*/
t_bool	intersect_sphere(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
	t_t2 *result)
{
	t_v3	ray_to_obj;
	float	t;
	float	y2;
	float	x;

	ray_to_obj = vec_sub(obj->pos, ray_start);
	t = vec_dot(ray_to_obj, ray_dir);
	if (t < 0)
		return (rt_false);
	y2 = vec_len_exp2(ray_to_obj) - t * t;
	if (y2 > obj->radius * obj->radius)
		return (rt_false);
	x = sqrtf(obj->radius * obj->radius - y2);
	result->t0 = t - x;
	result->t1 = t + x;
	return (rt_true);
}
