/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:15:12 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 20:32:18 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	zz_set_scene_third(t_ray_trace *rt, char scene_nbr)
{
	if (scene_nbr == 7)
	{
		if (!(set_scene_7(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 8)
	{
		if (!(set_scene_8(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 9)
	{
		if (!(set_scene_9(rt)))
			return (rt_false);
	}
	return (rt_true);
}

t_bool	zz_set_scene_second(t_ray_trace *rt, char scene_nbr)
{
	if (scene_nbr == 4)
	{
		if (!(set_scene_4(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 5)
	{
		if (!(set_scene_5(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 6)
	{
		if (!(set_scene_6(rt)))
			return (rt_false);
	}
	else if (!(zz_set_scene_third(rt, scene_nbr)))
		return (rt_false);
	return (rt_true);
}

t_bool	set_scene(t_ray_trace *rt, unsigned int scene_nbr)
{
	rt->final_color = 0;
	rt->proj_plane_dist = 300;
	if (scene_nbr == 0)
	{
		if (!(set_scene_0(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 1)
	{
		if (!(set_scene_1(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 2)
	{
		if (!(set_scene_2(rt)))
			return (rt_false);
	}
	else if (scene_nbr == 3)
	{
		if (!(set_scene_3(rt)))
			return (rt_false);
	}
	else if (!(zz_set_scene_second(rt, scene_nbr)))
		return (rt_false);
	return (rt_true);
}
