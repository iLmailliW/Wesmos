cmake_minimum_required(VERSION 4.0.3)
project(Wesmos)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(glfw
    URL https://github.com/glfw/glfw/releases/download/3.5.1/glfw-3.5.1.zip
)

FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	0af55ccecd98d4e5a8d1fad7de25ba429d60e863 #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

add_library(glad)

target_sources(glad
    PUBLIC
        src/glad/glad.c
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS 
            include
        FILES
            include/glad/glad.h
)

add_library(shaderprogram)

target_sources(shaderprogram
    PRIVATE
        src/shaderprogram.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/shaderprogram.h
)

target_link_libraries(shaderprogram
    PUBLIC
        glfw
        glad
)

add_library(projection INTERFACE)

target_sources(projection 
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/projection.h
)

add_library(ast)

target_sources(ast
    PRIVATE
        src/ast.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/ast.h
)

add_library(graph)

target_sources(graph
    PRIVATE
        src/graph.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/graph.h
)


add_library(lexer)

target_sources(lexer
    PRIVATE
        src/lexer.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/lexer.h
)

add_library(parser)

target_sources(parser
    PRIVATE
        src/parser.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/parser.h
)

add_executable(Wesmos)

target_sources(Wesmos
    PRIVATE
        main.cpp
)

target_link_libraries(Wesmos
    PRIVATE
        glfw
        glad
        glm::glm-header-only
        shaderprogram
        projection
        ast
        graph
        lexer
        parser
)