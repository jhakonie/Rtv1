/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:53:58 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 22:34:57 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(int ac, char **av)
{
	t_rtv1	rtv1;

	buffer_set(&rtv1, sizeof(t_rtv1), 0);
	rtv1.rt.scene = NULL;
	if (ac == 2 || ac == 1)
	{
		if (ac == 2)
			rtv1.rt.scene = av[1];
		if (!(rtv1_new(&rtv1, WIN_W, WIN_H)))
			return (-1);
		if (!(rtv1_run(&rtv1)))
		{
			rtv1.rt.objs = NULL;
			rtv1.rt.lights = NULL;
			rtv1_del(&rtv1);
			return (-1);
		}
		rtv1_del(&rtv1);
		return (0);
	}
	return (-1);
}
