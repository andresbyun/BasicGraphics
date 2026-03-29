cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "VCPKG toolchain file")

project ("BasicGraphics" VERSION 0.1.0 DESCRIPTION "Simple computer graphics project using SDL3")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB CURR_DIR_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(${PROJECT_NAME} SHARED ${CURR_DIR_SRC})

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL3::SDL3)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm-header-only)
