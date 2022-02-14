/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:32:44 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 15:28:26 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_set_cam(t_cam *cam)
{
	cam->pos = (t_v3){0, 0, 0};
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

static void	zz_set_objects_second(t_ray_trace *rt)
{
	rt->objs[3].type = cylinder;
	rt->objs[3].pos = (t_v3){20, 3, -30};
	rt->objs[3].rot = (t_v3){10, 0, 10};
	rt->objs[3].trans = (t_v3){10, 0, 0};
	rt->objs[3].dir = (t_v3){0, 1, 0};
	rt->objs[3].radius = 3;
	rt->objs[3].color = 0xffff00;
	rt->objs[4].type = cone;
	rt->objs[4].pos = (t_v3){-30, 3, -25};
	rt->objs[4].rot = (t_v3){20, 0, 3};
	rt->objs[4].trans = (t_v3){0, 0, 0};
	rt->objs[4].dir = (t_v3){0, 1, 0};
	rt->objs[4].radius = 0;
	rt->objs[4].ang = to_radians(18);
	rt->objs[4].color = 0xffffff;
}

static void	zz_set_objects(t_ray_trace *rt)
{
	rt->objs[0].type = plane;
	rt->objs[0].pos = (t_v3){-3, -5, -10};
	rt->objs[0].dir = (t_v3){0, 1, 0};
	rt->objs[0].rot = (t_v3){0, 0, -10};
	rt->objs[0].trans = (t_v3){0, 0, 0};
	rt->objs[0].color = 0x00ff00;
	rt->objs[1].type = sphere;
	rt->objs[1].pos = (t_v3){-4, -5, -10};
	rt->objs[1].rot = (t_v3){0, 0, 0};
	rt->objs[1].trans = (t_v3){0, 0, 0};
	rt->objs[1].radius = 3;
	rt->objs[1].color = 0x0000ff;
	rt->objs[2].type = sphere;
	rt->objs[2].pos = (t_v3){-4, 0, -10};
	rt->objs[2].rot = (t_v3){0, 0, 0};
	rt->objs[2].trans = (t_v3){2, 0, -5};
	rt->objs[2].radius = 3;
	rt->objs[2].color = 0xff0000;
	zz_set_objects_second(rt);
}

t_bool	set_scene_2(t_ray_trace *rt)
{
	rt->objs_size = 5;
	rt->objs = (t_object *)malloc(sizeof(t_object) * rt->objs_size);
	if (!(rt->objs))
		return (rt_false);
	buffer_set(rt->objs, sizeof(t_object), 0);
	zz_set_cam(&rt->cam);
	zz_set_objects(rt);
	set_object_transformation(rt);
	set_objects_function_ptr(rt);
	rt->ambient = 0.05f;
	rt->lights_size = 2;
	rt->lights = (t_light *)malloc(sizeof(t_light) * rt->lights_size);
	if (!(rt->lights))
	{
		free(rt->objs);
		return (rt_false);
	}
	rt->lights[0].pos = (t_v3){-20, 10, -5};
	rt->lights[0].intensity = 0.9f;
	rt->lights[1].pos = (t_v3){-20, 20, -5};
	rt->lights[1].intensity = 0.4f;
	rt->ray_start = rt->cam.pos;
	return (rt_true);
}
