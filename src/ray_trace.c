/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:40 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:08:46 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_nearest_intersection_point(t_ray_trace *rt,
	t_object **obj, size_t i)
{
	if (rt->result.t0 < 0 && rt->result.t1 > 0)
		rt->result.t0 = rt->result.t1;
	if (rt->result.t0 < rt->near && rt->result.t0 > 0)
	{
		rt->near = rt->result.t0;
		*obj = &rt->objs[i];
	}
}

t_bool	ray_trace(t_ray_trace *rt)
{
	size_t		i;
	t_object	*obj;

	obj = NULL;
	rt->near = INFINITY;
	i = 0;
	while (i < rt->objs_size)
	{
		rt->result.t0 = INFINITY;
		rt->result.t1 = INFINITY;
		if (rt->objs[i].intersect(rt->ray_dir, rt->ray_start,
				&rt->objs[i], &rt->result))
		{
			zz_nearest_intersection_point(rt, &obj, i);
		}
		i++;
	}
	if (obj)
		return (obj->normal(rt, obj));
	return (rt_false);
}
