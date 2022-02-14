/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:01:20 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/13 20:29:52 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "types.h"
# include "rtv1_math.h"

struct	s_parse_context
{
	char const	*p;
	char const	*e;
};
typedef struct s_parse_context		t_parse_context;

t_bool	parse_f32(t_parse_context *pc, float *n);
t_bool	parse_keyword(t_parse_context *pc, char const *k);
t_bool	parse_whitespace(t_parse_context *pc);
t_bool	parse_until(t_parse_context *pc, unsigned char c);
t_bool	parse_until_whitespace(t_parse_context *pc);
t_bool	parse_hex(t_parse_context *pc, unsigned char *str,
			unsigned int *hex, unsigned int len);
t_bool	parse_vec(t_parse_context *pc, t_v3 *vec);

#endif
