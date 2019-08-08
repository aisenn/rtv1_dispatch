cmake_minimum_required(VERSION 3.10)
project(rtv1 C)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

include_directories(libft libvec libavec miniLibX frameworks/SDL2.framework)
link_directories(libft libvec libavec miniLibX frameworks/SDL2.framework)

add_executable(rtv1
        intersect.c
        key.c
        light.c
        main.c
        mouse.c
        parser.c
        render.c
        set_objects.c
        split_window.c
        dispatch.c builton.c normal.c)

target_link_libraries(rtv1 PRIVATE -lft -lavec -lvec)

if(NOT SDL2_FOUND)
    set(SDL2_BIN_DIR "${CMAKE_CURRENT_BINARY_DIR}/sdl")

    message("Root Dir: ${CMAKE_CURRENT_BINARY_DIR}")

    include(ExternalProject)
    ExternalProject_Add(sdlLibrary
            PREFIX ${SDL2_BIN_DIR}/source
            INSTALL_DIR ${SDL2_BIN_DIR}
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${SDL2_BIN_DIR}
            GIT_REPOSITORY "https://github.com/SDL-mirror/SDL"
            GIT_TAG "release-2.0.9"
            GIT_PROGRESS ON)

    add_dependencies(rtv1 sdlLibrary)
    target_link_libraries(rtv1 PRIVATE ${SDL2_BIN_DIR}/lib/libSDL2-2.0.dylib -lft)
    target_include_directories(rtv1 PRIVATE ${SDL2_BIN_DIR}/include)
else()
    target_link_libraries(rtv1 PRIVATE ${SDL2_LIBRARIES} -lft)
    target_include_directories(rtv1 PRIVATE ${SDL2_INCLUDE_DIR})
endif()