/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:00:48 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:21:22 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_bool	zz_parse_f32_fractional(t_parse_context *pc, float *n)
{
	char const		*b;
	unsigned int	divisor;
	unsigned int	fractional;

	b = pc->p;
	*n = 0.0f;
	divisor = 1;
	fractional = 0;
	while (pc->p < pc->e && *pc->p >= '0' && *pc->p <= '9')
	{
		fractional = 10 * fractional + (*pc->p - '0');
		divisor = 10 * divisor;
		++pc->p;
	}
	if (pc->p == b)
	{
		return (rt_false);
	}
	*n = (float)fractional / (float)divisor;
	return (rt_true);
}

static t_bool	zz_parse_f32_sign_integer(t_parse_context *pc, float *s,
	float *n)
{
	char const		*b;
	unsigned int	integer;

	b = pc->p;
	*n = 0.0f;
	*s = 1.0f;
	if (pc->p < pc->e && *pc->p == '-')
	{
		++pc->p;
		*s = -1.0f;
	}
	integer = 0;
	while (pc->p < pc->e && *pc->p >= '0' && *pc->p <= '9')
	{
		integer = 10 * integer + (*pc->p - '0');
		++pc->p;
	}
	if (pc->p == b || (pc->p == (b + 1) && *s < 0))
	{
		pc->p = b;
		return (rt_false);
	}
	*n = (float)integer;
	return (rt_true);
}

t_bool	parse_f32(t_parse_context *pc, float *n)
{
	float	fractional;
	float	integer;
	float	sign;

	*n = 0.0f;
	if (!zz_parse_f32_sign_integer(pc, &sign, &integer))
	{
		return (rt_false);
	}
	fractional = 0.0f;
	if (pc->p < pc->e && *pc->p == '.')
	{
		++pc->p;
		zz_parse_f32_fractional(pc, &fractional);
	}
	*n = sign * (integer + fractional);
	return (rt_true);
}
