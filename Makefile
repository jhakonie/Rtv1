src_dir = src/
include_dirs = src/ build/libsdl2/include/
build_dir = build/

libsdl2_makefile = libsdl2/Makefile
libsdl2_lib = $(build_dir)libsdl2/lib/libSDL2.a
libsdl2_cflags = `$(build_dir)libsdl2/bin/sdl2-config --cflags`
libsdl2_ldflags = `$(build_dir)libsdl2/bin/sdl2-config --libs`

src_files = $(addprefix $(src_dir), \
	main.c \
	rtv1_new.c \
	rtv1_run.c \
	rtv1_del.c \
	draw.c \
	draw_pixel.c \
	draw_to_window.c \
	frame_buffer_del.c \
	frame_buffer_new.c \
	buffer_copy.c \
	buffer_set.c \
	vec_add.c \
	vec_sub.c \
	vec_negate.c \
	vec_multiply_f.c \
	vec_dot.c \
	vec_rotate_x.c \
	vec_rotate_y.c \
	vec_rotate_z.c \
	vec_rotate_xyz.c \
	vec_cross.c \
	vec_normalize.c \
	vec_len_exp2.c \
	light_pixel.c \
	to_radians.c \
	ray_trace.c \
	shadow_ray_trace.c \
	intersect_sphere.c \
	intersect_cylinder.c \
	intersect_cone.c \
	intersect_plane.c \
	shadow_ray_intersect.c \
	set_scene.c \
	normal_sphere.c \
	normal_plane.c \
	normal_cylinder.c \
	normal_cone.c \
	set_scene_1.c \
	set_scene_2.c \
	set_scene_3.c \
	set_scene_4.c \
	set_scene_5.c \
	set_scene_6.c \
	set_scene_7.c \
	set_scene_8.c \
	set_scene_9.c \
	set_scene_0.c \
	set_object_transformation.c \
	set_object_function_ptr.c \
	dyn_array_char_new_from_file.c \
	dyn_array_char_del.c \
	parse_f32.c \
	parse_hex.c \
	parse_keyword.c \
	parse_whitespace.c \
	parse_until.c \
	parse_until_whitespace.c \
	scene_new.c \
	scene_del.c \
	parse_vec.c \
	parse_cam.c \
	parse_objects.c \
	parse_lights.c \
)

obj_files = $(subst $(src_dir), $(build_dir), $(src_files:.c=.o))

NAME = RTv1

dependency_files = $(subst $(src_dir), $(build_dir), $(src_files:.c=.dep))
dependency_flags = -MT $(@) -MMD -MP -MF $(build_dir)$(*).dep

LD = gcc
LDFLAGS = -flto $(libsdl2_ldflags)
CC = gcc
CFLAGS = -O2 -flto -c -Wall -Werror -Wextra $(libsdl2_cflags) $(addprefix -I, $(include_dirs)) $(libsdl2_cflags)
CPPFLAGS = -D_REENTRANT

all: $(NAME)

$(NAME): $(obj_files) | $(build_dir)
	@ $(LD) $(obj_files) $(LDFLAGS) -o $(NAME)

$(obj_files): $(libsdl2_lib)

$(build_dir):
	mkdir $(build_dir)

$(build_dir)%.o: $(src_dir)%.c
$(build_dir)%.o: $(src_dir)%.c | $(build_dir)%.dep
	@ $(CC) $(CFLAGS) $(CPPFLAGS) $(dependency_flags) -o $(@) $(<)
	@ echo "[compiling: $(@)]"

$(dependency_files):

$(libsdl2_makefile):
	if test -d $(build_dir); then echo exists; else mkdir $(build_dir); fi
	cd libsdl2 && ./configure --prefix=$(abspath $(build_dir)libsdl2) --disable-shared --disable-video-wayland
	$(MAKE) --directory=libsdl2

$(libsdl2_lib): $(libsdl2_makefile) | $(build_dir)
	$(MAKE) --directory=libsdl2 install

clean:
	@ rm -f $(obj_files)
	@ echo "[removed $(NAME) o-files]"

fclean:
	rm -f RTv1
	if test -f $(libsdl2_makefile); then $(MAKE) AUTOMAKE=: --directory=libsdl2 distclean; fi
	rm -rf $(build_dir)
	@ echo [cleaned libsdl2]
	@ echo "[removed $(build_dir)]"
	@ echo "[removed $(NAME)]"

re: fclean all

.PHONY: all clean fclean re

include $(wildcard $(dependency_files))
