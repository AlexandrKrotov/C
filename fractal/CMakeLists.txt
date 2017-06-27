cmake_minimum_required(VERSION 3.7)
project(fractal)

include_directories(includes)

set(CMAKE_C_FLAG "{CMAKE_C_FLAG} -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -framework OpenCL")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenCL")

set(SOURCE_FILES author Makefile SRC/main.c includes/fractal.h SRC/ft_error.c
SRC/key_hook.c SRC/mouse_hook.c SRC/cl.c SRC/cl_check_succes.c
SRC/ftcl_get_device.c SRC/ftcl_load_program.c SRC/ft_init.c SRC/ft_create_img.c
SRC/ftcl_create_kernel.c SRC/ftcl_thread.c SRC/ftcl_release.c SRC/sierpinski.c
SRC/the_game.c SRC/init_mandatory.c SRC/init_bonus.c SRC/init_game.c SRC/space.c
SRC/key_swap.c SRC/fern.c)

add_executable(fractal ${SOURCE_FILES} includes/fractal.h)
set(HEADER_FILES includes/fractal.h includes/libft.h)

find_library(GPENGL_LIB OpenGL)
find_library(APPKIT_LIB AppKit)

target_link_libraries(fractal mlx ${GPENGL_LIB} ${APPKIT_LIB})
target_link_libraries(fractal ${CMAKE_SOURCE_DIR}/libft/libft.a)