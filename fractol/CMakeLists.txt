cmake_minimum_required(VERSION 3.6)
project(fractol)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(./../i) # headers
link_directories(libft minilibx) # libraries

set(SOURCE_FILES
       colour.c fractals.c main.c draw__other.c threads.c key_hooks.c) # sources

add_executable(fractol ${SOURCE_FILES}) # compilation

target_link_libraries(fractol libft.a libmlx.a "-framework OpenGL" "-framework AppKit") # linkage