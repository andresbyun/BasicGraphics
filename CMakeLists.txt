cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("BasicGraphicsApp")

file(GLOB CURR_DIR "examples/*.cpp")

add_executable (${PROJECT_NAME} "examples/00_color_screen.cpp")

add_subdirectory(utils)
target_link_libraries(${PROJECT_NAME} PRIVATE BasicGraphics)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm-header-only)
