/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:39:38 by jhakonie          #+#    #+#             */
/*   Updated: 2021/04/12 22:51:59 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "rtv1_math.h"

static void	zz_calculate_hex(unsigned int	*number, unsigned int *hex)
{
	t_rgba	num_part;

	num_part.r = number[0] * 16 + number[1];
	num_part.g = number[2] * 16 + number[3];
	num_part.b = number[4] * 16 + number[5];
	num_part.a = number[6] * 16 + number[7];
	*hex = (num_part.a << 24) | (num_part.r << 16)
		| (num_part.g << 8) | (num_part.b << 0);
}

t_bool	parse_hex(t_parse_context *pc, unsigned char *str,
	unsigned int *hex, unsigned int len)
{
	unsigned int	number[8];
	unsigned int	i;

	i = 0;
	if (!str || !hex || len > 8)
		return (rt_false);
	buffer_set(number, sizeof(unsigned int) * 8, 0);
	while (pc->p < pc->e && i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			number[i] = (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			number[i] = (str[i] - 55);
		else if (str[i] >= 'a' && str[i] <= 'f')
			number[i] = (str[i] - 87);
		else
			return (rt_false);
		i++;
	}
	zz_calculate_hex(number, hex);
	pc->p += len;
	return (rt_true);
}
