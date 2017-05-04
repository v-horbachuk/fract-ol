cmake_minimum_required(VERSION 3.6)
project(fractol)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(./../i) # headers
link_directories(libft minilibx) # libraries

set(SOURCE_FILES
       colour.c fractals.c fractals_2.c main.c) # sources

add_executable(fractol ${SOURCE_FILES}) # compilation

target_link_libraries(fractol libft.a libmlx.a "-framework OpenGL" "-framework AppKit") # linkage