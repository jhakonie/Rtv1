/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:55:18 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 13:26:04 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_math.h"

void	vec_normalize(t_v3 *vec)
{
	float	nor;
	float	inv_nor;

	nor = vec_len_exp2(*vec);
	if (nor > 0)
	{
		inv_nor = 1 / sqrtf(nor);
		vec->x *= inv_nor;
		vec->y *= inv_nor;
		vec->z *= inv_nor;
	}
}
