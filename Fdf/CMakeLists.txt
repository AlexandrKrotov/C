cmake_minimum_required(VERSION 3.6)
project(Fdf)

set(CMAKE_C_FLAG "{CMAKE_C_FLAG} -std=99 -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES main.c FdF.h ft_draw_line.c ft_parser.c libft/get_next_line.c ft_hook.c ft_error.c axis_rotation.c mulst_scale_shift.c all_calc.c all_free.c all_color.c bonus_ft.c drow_map.c ft_mouse_hook.c)

add_executable(Fdf ${SOURCE_FILES})

find_library(GPENGL_LIB OpenGL)
find_library(APPKIT_LIB AppKit)

target_link_libraries(Fdf mlx ${GPENGL_LIB} ${APPKIT_LIB})
target_link_libraries(Fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)