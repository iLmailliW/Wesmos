cmake_minimum_required(VERSION 4.0.3)

add_library(shaderprogram)

target_sources(shaderprogram
    PRIVATE
        shaderprogram.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ../include
        FILES
            ../include/shaderprogram.h
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
            ../include
        FILES
            ../include/projection.h
)

add_library(ast)

target_sources(ast
    PRIVATE
        ast.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ../include
        FILES
            ../include/ast.h
)

add_library(graph)

target_sources(graph
    PRIVATE
        graph.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ../include
        FILES
            ../include/graph.h
)


add_library(lexer)

target_sources(lexer
    PRIVATE
        lexer.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ../include
        FILES
            ../include/lexer.h
)

add_library(parser)

target_sources(parser
    PRIVATE
        parser.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ../include
        FILES
            ../include/parser.h
)