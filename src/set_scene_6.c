/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:46:27 by jsankari          #+#    #+#             */
/*   Updated: 2022/02/14 20:34:05 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_set_cam(t_cam *cam)
{
	cam->pos = (t_v3){0, 0, 6};
	cam->rot = (t_v3){0, 0, 0};
	cam->trans = (t_v3){0, 0, 0};
	cam->pos = vec_add(cam->pos, cam->trans);
	cam->dir = (t_v3){0, 0, -1};
	cam->dir = vec_rotate_xyz(cam->dir, cam->rot);
	cam->up_dir = (t_v3){0, -1, 0};
	cam->up_dir = vec_rotate_xyz(cam->up_dir, cam->rot);
	vec_normalize(&cam->up_dir);
	vec_normalize(&cam->dir);
	cam->side_dir = vec_cross(cam->dir, cam->up_dir);
	vec_normalize(&cam->side_dir);
}

static void	zz_set_objects(t_ray_trace *rt)
{
	rt->objs[0].type = sphere;
	rt->objs[0].pos = (t_v3){0, 0, 0};
	rt->objs[0].rot = (t_v3){0, 0, 0};
	rt->objs[0].trans = (t_v3){0, 0, 0};
	rt->objs[0].radius = 2;
	rt->objs[0].color = 0xff00ff;
}

t_bool	set_scene_6(t_ray_trace *rt)
{
	rt->objs_size = 1;
	rt->objs = (t_object *)malloc(sizeof(t_object) * rt->objs_size);
	if (!(rt->objs))
		return (rt_false);
	buffer_set(rt->objs, sizeof(*rt->objs), 0);
	zz_set_cam(&rt->cam);
	zz_set_objects(rt);
	set_object_transformation(rt);
	set_objects_function_ptr(rt);
	rt->ambient = 0.1f;
	rt->lights_size = 1;
	rt->lights = (t_light *)malloc(sizeof(t_light) * rt->lights_size);
	if (!(rt->lights))
	{
		free(rt->objs);
		return (rt_false);
	}
	rt->lights[0].pos = (t_v3){100, 100, 0};
	rt->lights[0].intensity = 0.9f;
	rt->ray_start = rt->cam.pos;
	return (rt_true);
}
