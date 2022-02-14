/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:02:54 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:45:30 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

enum	e_bool
{
	rt_false = 0,
	rt_true = 1
};
typedef enum e_bool					t_bool;

void	buffer_copy(void *xs, void const *ys, unsigned long size);
void	buffer_set(void *xs, unsigned long xs_size, unsigned char x);

/*
** note: sizes are in number of char-sized elements.
*/
struct	s_dyn_array_char
{
	char							*buffer;
	unsigned long int				buffer_size;
	unsigned long int				size;
};
typedef struct s_dyn_array_char		t_dyn_array_char;

t_bool	dyn_array_char_new_from_file(t_dyn_array_char *c,
			unsigned long int buffer_size, char const *filename);
void	dyn_array_char_del(t_dyn_array_char *c);

#endif
