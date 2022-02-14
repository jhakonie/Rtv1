/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:58:43 by jsankari          #+#    #+#             */
/*   Updated: 2022/02/14 15:28:10 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_set_cam(t_cam *cam)
{
	cam->pos = (t_v3){0, 0, 0};
	cam->rot = (t_v3){5, 10, 0};
	cam->trans = (t_v3){10, 15, 25};
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

static void	zz_set_objects_third(t_ray_trace *rt)
{
	rt->objs[3].type = sphere;
	rt->objs[3].pos = (t_v3){30, 4, -15};
	rt->objs[3].rot = (t_v3){0, 0, 0};
	rt->objs[3].trans = (t_v3){0, 0, 0};
	rt->objs[3].radius = 1;
	rt->objs[3].color = 0xff00aa;
	rt->objs[7].type = plane;
	rt->objs[7].pos = (t_v3){30, -3, -15};
	rt->objs[7].dir = (t_v3){-1, 1, 0};
	rt->objs[7].rot = (t_v3){0, 0, 0};
	rt->objs[7].trans = (t_v3){0, 0, 0};
	rt->objs[7].color = 0x6600ff;
	rt->objs[8].type = sphere;
	rt->objs[8].pos = (t_v3){-7, -1, -7};
	rt->objs[8].dir = (t_v3){100, 10, -10};
	rt->objs[8].rot = (t_v3){0, 0, 0};
	rt->objs[8].trans = (t_v3){0, 0, 0};
	rt->objs[8].radius = 4;
	rt->objs[8].color = 0x00ff00;
}

static void	zz_set_objects_second(t_ray_trace *rt)
{
	rt->objs[4].type = cone;
	rt->objs[4].pos = (t_v3){20, 10, -18};
	rt->objs[4].dir = (t_v3){0, 1, 0};
	rt->objs[4].rot = (t_v3){0, 0, 0};
	rt->objs[4].trans = (t_v3){0, 0, 0};
	rt->objs[4].radius = 0;
	rt->objs[4].ang = to_radians(10);
	rt->objs[4].color = 0x00ffff;
	rt->objs[5].type = cone;
	rt->objs[5].pos = (t_v3){4, 0, -20};
	rt->objs[5].dir = (t_v3){1, 1, 0};
	rt->objs[5].rot = (t_v3){0, 0, 0};
	rt->objs[5].trans = (t_v3){0, 0, 0};
	rt->objs[5].radius = 0;
	rt->objs[5].ang = to_radians(10);
	rt->objs[5].color = 0x6600bb;
	rt->objs[6].type = cylinder;
	rt->objs[6].pos = (t_v3){-3, -1, -20};
	rt->objs[6].dir = (t_v3){100, 10, -10};
	rt->objs[6].rot = (t_v3){0, 0, 0};
	rt->objs[6].trans = (t_v3){0, 0, 0};
	rt->objs[6].radius = 1;
	rt->objs[6].color = 0x00ff00;
	zz_set_objects_third(rt);
}

static void	zz_set_objects(t_ray_trace *rt)
{
	rt->objs[0].type = sphere;
	rt->objs[0].pos = (t_v3){10, 2, -15};
	rt->objs[0].rot = (t_v3){0, 0, 0};
	rt->objs[0].trans = (t_v3){0, 0, 0};
	rt->objs[0].radius = 2;
	rt->objs[0].color = 0xff00ff;
	rt->objs[1].type = plane;
	rt->objs[1].pos = (t_v3){-20, 0, -15};
	rt->objs[1].dir = (t_v3){1, 0, 0};
	rt->objs[1].rot = (t_v3){0, 0, 0};
	rt->objs[1].trans = (t_v3){0, 0, 0};
	rt->objs[1].color = 0xffffff;
	rt->objs[2].type = plane;
	rt->objs[2].pos = (t_v3){30, 4, -15};
	rt->objs[2].dir = (t_v3){-1, 0, 0};
	rt->objs[2].rot = (t_v3){0, 0, 0};
	rt->objs[2].trans = (t_v3){0, 0, 0};
	rt->objs[2].color = 0xff00aa;
	zz_set_objects_second(rt);
}

t_bool	set_scene_0(t_ray_trace *rt)
{
	rt->objs_size = 9;
	rt->objs = (t_object *)malloc(sizeof(t_object) * rt->objs_size);
	if (!(rt->objs))
		return (rt_false);
	buffer_set(rt->objs, sizeof(t_object) * rt->objs_size, 0);
	zz_set_cam(&rt->cam);
	zz_set_objects(rt);
	set_object_transformation(rt);
	set_objects_function_ptr(rt);
	rt->ambient = 0.15f;
	rt->lights_size = 2;
	rt->lights = (t_light *)malloc(sizeof(t_light) * rt->lights_size);
	if (!(rt->lights))
	{
		free(rt->objs);
		return (rt_false);
	}
	rt->lights[0].pos = (t_v3){0, 100, -10};
	rt->lights[0].intensity = 0.3f;
	rt->lights[1].pos = (t_v3){10, 10, -10};
	rt->lights[1].intensity = 0.7f;
	rt->ray_start = rt->cam.pos;
	return (rt_true);
}
