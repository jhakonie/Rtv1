/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:34:25 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 00:33:44 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "stdlib.h"

static void	zz_count_objects(t_parse_context *pc, size_t *objs_size, char *ptr)
{
	while (pc->p < pc->e && parse_until(pc, 's'))
	{
		*objs_size += 1;
	}
	pc->p = ptr;
	while (pc->p < pc->e && parse_until(pc, 'p'))
	{
		*objs_size += 1;
	}
	pc->p = ptr;
	while (pc->p < pc->e && parse_until(pc, '*'))
	{
		*objs_size += 1;
	}
	pc->p = ptr;
	while (pc->p < pc->e && parse_until(pc, '^'))
	{
		*objs_size += 1;
	}
	pc->p = ptr;
}

static t_bool	zz_parse_objects(t_parse_context *pc,
	t_ray_trace *rt, char *ptr)
{
	rt->objs = NULL;
	rt->objs_size = 0;
	rt->objs_index = 0;
	zz_count_objects(pc, &rt->objs_size, ptr);
	if (rt->objs_size == 0)
		return (rt_false);
	rt->objs = (t_object *)malloc(sizeof(t_object) * rt->objs_size);
	if (!(rt->objs))
		return (rt_false);
	buffer_set(rt->objs, sizeof(t_object) * rt->objs_size, 0);
	if (!(parse_objects(pc, rt, ptr)))
	{
		free(rt->objs);
		return (rt_false);
	}
	return (rt_true);
}

static t_bool	zz_parse_scene(t_parse_context *pc, t_ray_trace *rt, char *ptr)
{
	pc->p = ptr;
	if (!(zz_parse_objects(pc, rt, ptr)))
		return (rt_false);
	pc->p = ptr;
	if (!(parse_lights(pc, rt, ptr)))
	{
		free(rt->objs);
		return (rt_false);
	}
	set_object_transformation(rt);
	set_objects_function_ptr(rt);
	rt->final_color = 0;
	rt->proj_plane_dist = 500;
	rt->ray_start = rt->cam.pos;
	return (rt_true);
}

t_bool	scene_new(t_ray_trace *rt)
{
	t_dyn_array_char	txt;
	const char			*ptr;
	t_parse_context		pc;

	if (!(dyn_array_char_new_from_file(&txt, 1024, rt->scene)))
		return (rt_false);
	pc.p = (char const *)txt.buffer;
	pc.e = (char const *)(txt.buffer + txt.size);
	ptr = (char const *)txt.buffer;
	if (!parse_cam(&pc, &rt->cam))
	{
		dyn_array_char_del(&txt);
		return (rt_false);
	}
	if (!(zz_parse_scene(&pc, rt, (char *)ptr)))
	{
		dyn_array_char_del(&txt);
		return (rt_false);
	}
	dyn_array_char_del(&txt);
	return (rt_true);
}
