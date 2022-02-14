/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_function_ptr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:15:24 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 15:02:37 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_objects_function_ptr(t_ray_trace *rt)
{
	size_t	i;

	i = 0;
	while (i < rt->objs_size)
	{
		rt->objs[i].intersect = &intersect_cone;
		rt->objs[i].normal = &normal_cone;
		if (rt->objs[i].type == sphere)
		{
			rt->objs[i].intersect = &intersect_sphere;
			rt->objs[i].normal = &normal_sphere;
		}
		else if (rt->objs[i].type == plane)
		{
			rt->objs[i].intersect = &intersect_plane;
			rt->objs[i].normal = &normal_plane;
		}
		else if (rt->objs[i].type == cylinder)
		{
			rt->objs[i].intersect = &intersect_cylinder;
			rt->objs[i].normal = &normal_cylinder;
		}
		i++;
	}
}
