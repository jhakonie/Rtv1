/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:00:32 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 23:34:19 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_bool	zz_parse_spots(t_parse_context *pc, t_ray_trace *rt)
{
	size_t	i;

	i = 0;
	while (parse_until(pc, 'l'))
	{
		if (!(parse_whitespace(pc))
			|| !(parse_vec(pc, &rt->lights[i].pos))
			|| !(parse_whitespace(pc))
			|| !(parse_f32(pc, &rt->lights[i].intensity)))
		{
			return (rt_false);
		}
		i++;
	}
	return (rt_true);
}

static t_bool	zz_parse_ambient(t_parse_context *pc, float *ambient)
{
	if (!(parse_until(pc, '!'))
		|| !(parse_whitespace(pc))
		|| !(parse_f32(pc, ambient)))
		return (rt_false);
	return (rt_true);
}

static void	zz_count_lights(t_parse_context *pc, size_t *lights_size)
{
	while (parse_until(pc, 'l'))
		*lights_size += 1;
}

t_bool	parse_lights(t_parse_context *pc, t_ray_trace *rt, char *ptr)
{
	rt->lights_size = 0;
	rt->lights = NULL;
	if (!(zz_parse_ambient(pc, &rt->ambient)))
		return (rt_false);
	pc->p = ptr;
	zz_count_lights(pc, &rt->lights_size);
	pc->p = ptr;
	rt->lights = (t_light *)malloc(sizeof(t_light) * rt->lights_size);
	if (!(rt->lights))
		return (rt_false);
	buffer_set(rt->lights, sizeof(t_light) * rt->lights_size, 0);
	if (!(zz_parse_spots(pc, rt)))
		return (rt_false);
	pc->p = ptr;
	return (rt_true);
}
