cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("BasicSimulatorApp")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "src/main.cpp")

add_subdirectory(BasicSimulator)
target_link_libraries(${PROJECT_NAME} PRIVATE BasicSimLib)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
