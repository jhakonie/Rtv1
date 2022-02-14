/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate_xyz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:01:44 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/06 14:05:18 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_math.h"

t_v3	vec_rotate_xyz(t_v3 vec, t_v3 rot)
{
	t_v3	res;

	res = vec;
	vec_rotate_x(&res, to_radians(rot.x));
	vec_rotate_y(&res, to_radians(rot.y));
	vec_rotate_z(&res, to_radians(rot.z));
	return (res);
}
