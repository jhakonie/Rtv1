/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_until_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:50:36 by jsankari          #+#    #+#             */
/*   Updated: 2022/02/09 16:35:27 by jhakonie         ###   ########.fr       */
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

t_bool	parse_until_whitespace(t_parse_context *pc)
{
	char const	*beginning;

	beginning = pc->p;
	while (pc->p < pc->e)
	{
		if (zz_is_whitespace(*pc->p) == rt_true)
			return (rt_true);
		pc->p++;
	}
	if (pc->p == pc->e)
		pc->p = beginning;
	return (rt_false);
}
