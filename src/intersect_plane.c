/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:20:54 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 15:37:42 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	intersect_plane(t_v3 ray_dir, t_v3 ray_start,
	t_object *obj, t_t2 *res)
{
	t_v3	ray_obj;
	float	numerator;
	float	denominator;

	vec_normalize(&obj->dir);
	ray_obj = vec_sub(ray_start, obj->pos);
	numerator = vec_dot(ray_obj, obj->dir);
	denominator = vec_dot(ray_dir, obj->dir);
	if ((denominator < 0 && numerator > 0)
		|| (denominator > 0 && numerator < 0))
	{
		res->t0 = -numerator / denominator;
		res->t1 = -1;
		return (rt_true);
	}
	return (rt_false);
}
