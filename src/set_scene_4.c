/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:35:38 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 15:28:40 by jsankari         ###   ########.fr       */
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

static void	zz_set_objects_third(t_ray_trace *rt)
{
	rt->objs[6].type = cylinder;
	rt->objs[6].pos = (t_v3){-3, -3, -10};
	rt->objs[6].dir = (t_v3){1, 2, 0};
	rt->objs[6].rot = (t_v3){0, 0, 0};
	rt->objs[6].trans = (t_v3){0, 0, 0};
	rt->objs[6].radius = 2;
	rt->objs[6].color = 0x33cc22;
	rt->objs[7].type = plane;
	rt->objs[7].pos = (t_v3){-3, -3, -50};
	rt->objs[7].dir = (t_v3){0, 0, 1};
	rt->objs[7].rot = (t_v3){0, 0, 0};
	rt->objs[7].trans = (t_v3){0, 0, 0};
	rt->objs[7].color = 0xffffff;
	rt->objs[8].type = plane;
	rt->objs[8].pos = (t_v3){-3, -20, -50};
	rt->objs[8].dir = (t_v3){0, 1, 0};
	rt->objs[8].rot = (t_v3){0, 0, 0};
	rt->objs[8].trans = (t_v3){0, 0, 0};
	rt->objs[8].color = 0xbb33bb;
}

static void	zz_set_objects_second(t_ray_trace *rt)
{
	rt->objs[3].type = sphere;
	rt->objs[3].pos = (t_v3){4, 0, -6};
	rt->objs[3].rot = (t_v3){0, 0, 0};
	rt->objs[3].trans = (t_v3){0, 0, 0};
	rt->objs[3].radius = 1;
	rt->objs[3].color = 0x55aa55;
	rt->objs[4].type = cone;
	rt->objs[4].pos = (t_v3){-25, 0, -30};
	rt->objs[4].rot = (t_v3){0, 0, 0};
	rt->objs[4].trans = (t_v3){0, 0, 0};
	rt->objs[4].dir = (t_v3){0, 1, 0};
	rt->objs[4].radius = 0.0f;
	rt->objs[4].ang = to_radians(13);
	rt->objs[4].color = 0x00ffff;
	rt->objs[5].type = sphere;
	rt->objs[5].pos = (t_v3){50, 19, -50};
	rt->objs[5].rot = (t_v3){0, 0, 0};
	rt->objs[5].trans = (t_v3){0, 0, 0};
	rt->objs[5].radius = 10;
	rt->objs[5].color = 0x0af00ff;
	zz_set_objects_third(rt);
}

static void	zz_set_objects(t_ray_trace *rt)
{
	rt->objs[0].type = sphere;
	rt->objs[0].pos = (t_v3){48, 30, -50};
	rt->objs[0].rot = (t_v3){0, 0, 0};
	rt->objs[0].trans = (t_v3){0, 0, 0};
	rt->objs[0].radius = 6;
	rt->objs[0].color = 0xffaaff;
	rt->objs[1].type = sphere;
	rt->objs[1].pos = (t_v3){-35, 0, -50};
	rt->objs[1].rot = (t_v3){0, 0, 0};
	rt->objs[1].trans = (t_v3){0, 0, 0};
	rt->objs[1].radius = 10;
	rt->objs[1].color = 0x10f099;
	rt->objs[2].type = cone;
	rt->objs[2].pos = (t_v3){-4, 2, -10};
	rt->objs[2].dir = (t_v3){-3, 1, 0};
	rt->objs[2].rot = (t_v3){0, 0, 0};
	rt->objs[2].trans = (t_v3){0, 0, 0};
	rt->objs[2].radius = 0;
	rt->objs[2].ang = to_radians(15);
	rt->objs[2].color = 0xffff00;
	zz_set_objects_second(rt);
}

t_bool	set_scene_4(t_ray_trace *rt)
{
	rt->objs_size = 9;
	rt->objs = (t_object *)malloc(sizeof(t_object) * rt->objs_size);
	if (!(rt->objs))
		return (rt_false);
	buffer_set(rt->objs, sizeof(*rt->objs), 0);
	zz_set_cam(&rt->cam);
	zz_set_objects(rt);
	set_object_transformation(rt);
	set_objects_function_ptr(rt);
	rt->ambient = 0.15;
	rt->lights_size = 3;
	rt->lights = (t_light *)malloc(sizeof(t_light) * rt->lights_size);
	if (!(rt->lights))
	{
		free(rt->objs);
		return (rt_false);
	}
	rt->lights[0].pos = (t_v3){-100, 4, 10};
	rt->lights[0].intensity = 0.3f;
	rt->lights[1].pos = (t_v3){0, -10, 15};
	rt->lights[1].intensity = 0.5f;
	rt->lights[2].pos = (t_v3){0, 60, 50};
	rt->lights[2].intensity = 0.1f;
	rt->ray_start = rt->cam.pos;
	return (rt_true);
}
