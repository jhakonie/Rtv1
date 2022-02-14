/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:24:51 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 15:24:53 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	buffer_copy(void *xs, void const *ys, unsigned long size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)xs)[i] = ((unsigned char *)ys)[i];
		++i;
	}
}
