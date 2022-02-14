/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:24:56 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 15:24:57 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	buffer_set(void *xs, unsigned long xs_size, unsigned char x)
{
	unsigned long	i;

	i = 0;
	while (i < xs_size)
	{
		((unsigned char *)xs)[i] = x;
		++i;
	}
}
