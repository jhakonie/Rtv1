/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:43:23 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 22:21:39 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene_del(t_ray_trace *rt)
{
	free(rt->objs);
	free(rt->lights);
	rt->objs_size = 0;
	rt->lights_size = 0;
	rt->objs_index = 0;
	buffer_set(&rt->cam, sizeof(t_cam), 0);
}
