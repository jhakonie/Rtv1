/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:11:30 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:27:59 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_bool	zz_parse_sphere(t_parse_context *pc, t_ray_trace *rt)
{
	while (parse_until(pc, 's'))
	{
		if (!(parse_whitespace(pc))
			|| !(parse_hex(pc,
					(unsigned char *)pc->p, &rt->objs[rt->objs_index].color, 6))
			|| !(parse_until_whitespace(pc))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].pos))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].dir))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].trans))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].rot))
			|| !(parse_whitespace(pc))
			|| !(parse_f32(pc, &rt->objs[rt->objs_index].radius)))
		{
			return (rt_false);
		}
		rt->objs[rt->objs_index].type = sphere;
		rt->objs_index++;
	}
	return (rt_true);
}

static t_bool	zz_parse_cylinder(t_parse_context *pc, t_ray_trace *rt)
{
	while (parse_until(pc, '*'))
	{
		if (!(parse_whitespace(pc))
			|| !(parse_hex(pc,
					(unsigned char *)pc->p, &rt->objs[rt->objs_index].color, 6))
			|| !(parse_until_whitespace(pc))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].pos))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].dir))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].trans))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].rot))
			|| !(parse_whitespace(pc))
			|| !(parse_f32(pc, &rt->objs[rt->objs_index].radius)))
		{
			return (rt_false);
		}
		rt->objs[rt->objs_index].type = cylinder;
		rt->objs_index++;
	}
	return (rt_true);
}

static t_bool	zz_parse_cone(t_parse_context *pc, t_ray_trace *rt)
{
	while (parse_until(pc, '^'))
	{
		if (!(parse_whitespace(pc))
			|| !(parse_hex(pc,
					(unsigned char *)pc->p, &rt->objs[rt->objs_index].color, 6))
			|| !(parse_until_whitespace(pc))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].pos))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].dir))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].trans))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].rot))
			|| !(parse_whitespace(pc))
			|| !(parse_f32(pc, &rt->objs[rt->objs_index].radius))
			|| !(parse_whitespace(pc))
			|| !(parse_f32(pc, &rt->objs[rt->objs_index].ang)))
			return (rt_false);
		rt->objs[rt->objs_index].ang = to_radians(rt->objs[rt->objs_index].ang);
		rt->objs[rt->objs_index].type = cone;
		rt->objs_index++;
	}
	return (rt_true);
}

static t_bool	zz_parse_plane(t_parse_context *pc, t_ray_trace *rt)
{
	while (parse_until(pc, 'p'))
	{
		if (!(parse_whitespace(pc))
			|| !(parse_hex(pc,
					(unsigned char *)pc->p, &rt->objs[rt->objs_index].color, 6))
			|| !(parse_until_whitespace(pc))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].pos))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].dir))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].trans))
			|| !(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->objs[rt->objs_index].rot))
			|| !(parse_whitespace(pc)))
		{
			return (rt_false);
		}
		rt->objs[rt->objs_index].type = plane;
		rt->objs_index++;
	}
	return (rt_true);
}

t_bool	parse_objects(t_parse_context *pc, t_ray_trace *rt, char *ptr)
{
	if (!zz_parse_sphere(pc, rt))
		return (rt_false);
	pc->p = ptr;
	if (!zz_parse_plane(pc, rt))
		return (rt_false);
	pc->p = ptr;
	if (!zz_parse_cylinder(pc, rt))
		return (rt_false);
	pc->p = ptr;
	if (!zz_parse_cone(pc, rt))
		return (rt_false);
	pc->p = ptr;
	return (rt_true);
}
