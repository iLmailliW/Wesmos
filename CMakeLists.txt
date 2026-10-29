cmake_minimum_required(VERSION 4.0.3)
project(Wesmos)

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

add_library(glad INTERFACE)

target_sources(glad
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS 
            include
        FILES
            include/glad/glad.h
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
)