/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:32:38 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 19:42:04 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	zz_set_cam(t_cam *cam)
{
	cam->pos = vec_add(cam->pos, cam->trans);
	cam->dir = vec_rotate_xyz(cam->dir, cam->rot);
	vec_normalize(&cam->dir);
	cam->up_dir = (t_v3){0, -1, 0};
	if (cam->dir.x == 0 && cam->dir.y == -1 && cam->dir.z == 0)
		cam->up_dir = (t_v3){0, 0, -1};
	cam->up_dir = vec_rotate_xyz(cam->up_dir, cam->rot);
	vec_normalize(&cam->up_dir);
	cam->side_dir = vec_cross(cam->dir, cam->up_dir);
	vec_normalize(&cam->side_dir);
}

t_bool	parse_cam(t_parse_context *pc, t_cam *cam)
{
	if (!(parse_until(pc, '#'))
		|| !(parse_whitespace(pc))
		|| !(parse_vec(pc, &cam->pos))
		|| !(parse_whitespace(pc))
		|| !(parse_vec(pc, &cam->dir))
		|| !(parse_whitespace(pc))
		|| !(parse_vec(pc, &cam->trans))
		|| !(parse_whitespace(pc))
		|| !(parse_vec(pc, &cam->rot)))
	{
		return (rt_false);
	}
	zz_set_cam(cam);
	return (rt_true);
}
