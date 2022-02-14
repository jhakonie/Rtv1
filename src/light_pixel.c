/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:04:04 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/09 17:28:28 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_math.h"

void	light_pixel(unsigned int *color, float intensity)
{
	t_rgba			new_color;
	float			shade_factor;

	shade_factor = intensity;
	if (intensity < 0)
		shade_factor = 0;
	if (shade_factor > 1)
		shade_factor = 1;
	new_color.r = (((*color & 0x000000FF) >> 0) * (shade_factor));
	new_color.g = (((*color & 0x0000FF00) >> 8) * (shade_factor));
	new_color.b = (((*color & 0x00FF0000) >> 16) * (shade_factor));
	*color = (new_color.b << 16)
		| (new_color.g << 8) | (new_color.r << 0);
}
