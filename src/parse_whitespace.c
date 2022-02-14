/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:01:13 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/08 18:01:14 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_bool	zz_is_whitespace(char c)
{
	if (c != ' ' && c != '\f' && c != '\n' && c != '\r' && c != '\t'
		&& c != '\t')
	{
		return (rt_false);
	}
	return (rt_true);
}

t_bool	parse_whitespace(t_parse_context *pc)
{
	char const	*b;

	b = pc->p;
	while (pc->p < pc->e && zz_is_whitespace(*pc->p))
	{
		++pc->p;
	}
	if (pc->p == b)
	{
		return (rt_false);
	}
	return (rt_true);
}
