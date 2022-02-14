/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keyword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:01:02 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:20:09 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_keyword(t_parse_context *pc, char const *k)
{
	unsigned long int	i;

	i = 0;
	while (k[i] != '\0')
	{
		if (pc->p + i >= pc->e)
		{
			return (rt_false);
		}
		if (pc->p[i] != k[i])
		{
			return (rt_false);
		}
		++i;
	}
	pc->p = pc->p + i;
	return (rt_true);
}
