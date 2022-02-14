/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:22:50 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 16:36:02 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "types.h"
#include "rtv1_math.h"

t_bool	parse_vec(t_parse_context *pc, t_v3 *vec)
{
	if (!(parse_f32(pc, &vec->x))
		|| !(parse_keyword(pc, ","))
		|| !(parse_f32(pc, &vec->y))
		|| !(parse_keyword(pc, ","))
		|| !(parse_f32(pc, &vec->z)))
		return (rt_false);
	return (rt_true);
}
