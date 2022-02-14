/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:22:45 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 19:54:10 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL2/SDL.h"
# include "unistd.h"
# include "types.h"
# include "parse.h"
# include "frame_buffer.h"
# include "rtv1_math.h"

# define WIN_W (840)
# define WIN_H (512)

struct s_light
{
	t_v3	pos;
	float	intensity;
};
typedef struct s_light		t_light;

struct s_cam
{
	t_v3	pos;
	t_v3	dir;
	t_v3	rot;
	t_v3	trans;
	t_v3	up_dir;
	t_v3	side_dir;
};
typedef struct s_cam		t_cam;

typedef enum e_type
{
	sphere,
	plane,
	cone,
	cylinder,
}	t_type;

typedef struct s_object		t_object;

typedef struct s_ray_trace	t_ray_trace;

struct s_object
{
	t_type			type;
	t_v3			pos;
	t_v3			dir;
	t_v3			rot;
	t_v3			trans;
	unsigned int	color;
	float			radius;
	float			ang;
	t_bool			((*intersect)(t_v3, t_v3, t_object *, t_t2 *));
	t_bool			((*normal)(t_ray_trace *, t_object *));
};

typedef struct s_object		t_object;

typedef struct s_ray_trace
{
	char			*scene;
	t_cam			cam;
	t_object		*objs;
	size_t			objs_size;
	size_t			objs_index;
	t_light			*lights;
	size_t			lights_size;
	t_v3			ray_dir;
	t_v3			ray_start;
	t_v3			proj_plane_center;
	unsigned int	proj_plane_dist;
	float			near;
	t_t2			result;
	unsigned int	transmission;
	t_v3			new_start;
	float			light_distance;
	t_v3			light_direction;
	unsigned int	final_color;
	float			ambient;
}	t_ray_trace;

struct				s_rtv1
{
	SDL_Event			event;
	SDL_Window			*window;
	SDL_Texture			*texture;
	SDL_Renderer		*renderer;
	t_frame_buffer		frame_buffer;
	t_bool				run;
	t_bool				quit_as_expected;
	t_bool				draw;
	t_ray_trace			rt;
};
typedef struct s_rtv1		t_rtv1;

t_bool		rtv1_new(t_rtv1 *rtv1, unsigned int window_width,
				unsigned int window_height);
t_bool		rtv1_run(t_rtv1 *rtv1);
void		rtv1_del(t_rtv1 *rtv1);
t_bool		scene_new(t_ray_trace *rt);
void		scene_del(t_ray_trace *rt);
t_bool		parse_cam(t_parse_context *pc, t_cam *cam);
t_bool		parse_objects(t_parse_context *pc, t_ray_trace *rt,
				char *ptr);
t_bool		parse_lights(t_parse_context *pc, t_ray_trace *rt,
				char *ptr);
t_bool		set_scene(t_ray_trace *rt, unsigned int scene_nbr);
t_bool		set_scene_1(t_ray_trace *rt);
t_bool		set_scene_2(t_ray_trace *rt);
t_bool		set_scene_3(t_ray_trace *rt);
t_bool		set_scene_4(t_ray_trace *rt);
t_bool		set_scene_5(t_ray_trace *rt);
t_bool		set_scene_6(t_ray_trace *rt);
t_bool		set_scene_7(t_ray_trace *rt);
t_bool		set_scene_8(t_ray_trace *rt);
t_bool		set_scene_9(t_ray_trace *rt);
t_bool		set_scene_0(t_ray_trace *rt);
void		set_object_transformation(t_ray_trace *rt);
void		set_objects_function_ptr(t_ray_trace *rt);
void		draw(t_rtv1 *rtv1);
void		draw_pixel(t_p2 point, t_frame_buffer *fb, unsigned int color);
void		draw_to_window(t_rtv1 *rtv1);
t_bool		ray_trace(t_ray_trace *rt);
t_bool		shadow_ray_trace(t_ray_trace *rt, t_v3 hit, t_v3 hit_normal,
				t_object *obj);
t_bool		intersect_sphere(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
				t_t2 *result);
t_bool		intersect_cylinder(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
				t_t2 *res);
t_bool		intersect_cone(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
				t_t2 *res);
t_bool		intersect_plane(t_v3 ray_dir, t_v3 ray_start, t_object *obj,
				t_t2 *res);
void		shadow_ray_intersect(t_ray_trace *rt, t_v3 hit,
				t_v3 hit_normal, size_t i);
t_bool		normal_sphere(t_ray_trace *rt, t_object *obj);
t_bool		normal_plane(t_ray_trace *rt, t_object *obj);
t_bool		normal_cylinder(t_ray_trace *rt, t_object *obj);
t_bool		normal_cone(t_ray_trace *rt, t_object *obj);

#endif
