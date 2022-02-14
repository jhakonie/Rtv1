/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_math.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:14:07 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/07 21:22:02 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MATH_H
# define RTV1_MATH_H

# include "types.h"
# include "math.h"

# define PI (3.14159f)

struct	s_v3
{
	float	x;
	float	y;
	float	z;
};
typedef struct s_v3	t_v3;

t_v3	vec_add(t_v3 a, t_v3 b);
t_v3	vec_sub(t_v3 a, t_v3 b);
t_v3	vec_multiply_f(t_v3 vec, float f);
t_v3	vec_negate(t_v3 vec);
float	vec_dot(t_v3 a, t_v3 b);
t_v3	vec_cross(t_v3 a, t_v3 b);
void	vec_normalize(t_v3 *vec);
float	vec_len_exp2(t_v3 vec);
void	vec_rotate_x(t_v3 *vec, float rad);
void	vec_rotate_y(t_v3 *vec, float rad);
void	vec_rotate_z(t_v3 *vec, float rad);
t_v3	vec_rotate_xyz(t_v3 vec, t_v3 rot);

struct	s_p2
{
	float	x;
	float	y;
};
typedef struct s_p2	t_p2;

typedef struct s_quadratic_solve
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	numerator;
}	t_quadratic_solve;

struct		s_t2
{
	float	t0;
	float	t1;
};
typedef struct s_t2	t_t2;

typedef struct s_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_rgba;

void	light_pixel(unsigned int *color, float distance);
float	to_radians(float deg);

#endif
