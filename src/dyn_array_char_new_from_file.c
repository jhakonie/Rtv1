/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_array_char_new_from_file.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:42:04 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:44:02 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "stdlib.h"
#include "unistd.h"
#include "parse.h"

static t_bool	zz_dyn_array_char_add_back_be(t_dyn_array_char *c,
	void const *b, void const *e)
{
	void				*new_buffer;
	unsigned long int	new_size;

	new_size = c->size + (e - b);
	if (c->buffer_size < new_size)
	{
		if (new_size < (2 * c->buffer_size))
		{
			new_size = 2 * c->buffer_size;
		}
		new_buffer = (void *)malloc(new_size);
		if (!new_buffer)
		{
			return (rt_false);
		}
		buffer_copy(new_buffer, c->buffer, c->buffer_size);
		free(c->buffer);
		c->buffer = new_buffer;
		c->buffer_size = new_size;
	}
	buffer_copy(c->buffer + c->size, b, e - b);
	c->size += e - b;
	return (rt_true);
}

static t_bool	zz_dyn_array_char_new(t_dyn_array_char *c,
	unsigned long int buffer_size)
{
	buffer_set(c, sizeof(*c), 0);
	if (buffer_size)
	{
		c->buffer = (char *)malloc(buffer_size);
		if (!c->buffer)
		{
			return (rt_false);
		}
		c->buffer_size = buffer_size;
	}
	c->size = 0;
	return (rt_true);
}

static t_bool	zz_on_error(t_dyn_array_char *c, int fd)
{
	close(fd);
	dyn_array_char_del(c);
	return (rt_false);
}

t_bool	dyn_array_char_new_from_file(t_dyn_array_char *c,
	unsigned long int buffer_size, char const *filename)
{
	char		buffer[4096];
	int			fd;
	ssize_t		read_size;

	if (!zz_dyn_array_char_new(c, buffer_size))
		return (rt_false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (zz_on_error(c, fd));
	while (rt_true)
	{
		read_size = read(fd, buffer, sizeof(buffer));
		if (read_size <= 0)
		{
			break ;
		}
		if (!zz_dyn_array_char_add_back_be(c, buffer, buffer + read_size))
			return (zz_on_error(c, fd));
	}
	if (read_size == -1)
		return (zz_on_error(c, fd));
	close(fd);
	return (rt_true);
}
