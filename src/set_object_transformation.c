/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_transformation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:13:28 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 15:05:08 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_object_transformation(t_ray_trace *rt)
{
	size_t	i;

	i = 0;
	while (i < rt->objs_size)
	{
		rt->objs[i].pos = vec_add(rt->objs[i].pos, rt->objs[i].trans);
		rt->objs[i].dir = vec_rotate_xyz(rt->objs[i].dir, rt->objs[i].rot);
		i++;
	}
}
