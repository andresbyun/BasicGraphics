file(GLOB CURR_DIR_SRC *.cpp)
file(GLOB CURR_DIR_HEADER *.hpp)

set(UTIL_LIB_NAME "BasicGraphics")

add_library(${UTIL_LIB_NAME} STATIC ${CURR_DIR_SRC} ${CURR_DIR_HEADER})

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${UTIL_LIB_NAME} PUBLIC SDL3::SDL3)

target_include_directories(${UTIL_LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
