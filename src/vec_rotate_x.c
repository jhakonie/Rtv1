/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:58:34 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 20:24:22 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_math.h"

void	vec_rotate_x(t_v3 *vec, float rad)
{
	t_v3	prev;

	prev.z = vec->z;
	prev.y = vec->y;
	vec->z = prev.z * cos(rad) - prev.y * sin(rad);
	vec->y = prev.z * sin(rad) + prev.y * cos(rad);
}
