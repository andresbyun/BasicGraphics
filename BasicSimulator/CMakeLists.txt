file(GLOB CURR_DIR_SRC *.cpp)
file(GLOB CURR_DIR_HEADER *.hpp)

add_library(BasicSimLib ${CURR_DIR_SRC} ${CURR_DIR_HEADER})

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(BasicSimLib PRIVATE SDL3::SDL3)

target_include_directories(BasicSimLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
