cmake_minimum_required(VERSION 3.7)
project(RTv1)

include_directories(includes)
if(Darwin)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit -framework OpenCL -lmlx")
else(LINUX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx_Linux -L/usr/X11/lib -lXext -lX11 -lm")
endif()
set(SOURCE_FILES SRC/main.c includes/rtv1.h SRC/ft_key_hook.c SRC/ft_exit.c SRC/ft_mous_hook.c SRC/ft_render.c SRC/ft_init_all.c SRC/ft_vector_math.c SRC/ft_create_scene_map.c SRC/ft_sphere.c SRC/ft_plane.c SRC/ft_cylinder.c SRC/ft_cone.c SRC/ft_light.c SRC/ft_phong.c SRC/ft_rotate_axis.c SRC/ft_antialiasing.c)

add_executable(RTv1 ${SOURCE_FILES} includes/rtv1.h)
set(HEADER_FILES includes/rtv1.h includes/libft.h)

find_library(GPENGL_LIB OpenGL)
find_library(APPKIT_LIB AppKit)

target_link_libraries(RTv1 ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(RTv1 ${CMAKE_SOURCE_DIR}/minilibx/libmlx_Linux.a)