/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:53:27 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:17:33 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_until(t_parse_context *pc, unsigned char c)
{
	char const	*b;

	b = pc->p;
	while (pc->p < pc->e)
	{
		if (*pc->p == c)
		{
			pc->p++;
			return (rt_true);
		}
		pc->p++;
	}
	if (pc->p == pc->e)
		pc->p = b;
	return (rt_false);
}
