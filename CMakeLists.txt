cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("BasicGraphics" VERSION 0.1.0 DESCRIPTION "Simple computer graphics project using SDL3")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB CURR_DIR_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(${PROJECT_NAME} STATIC ${CURR_DIR_SRC})

target_include_directories(BasicGraphics
                           PUBLIC 
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/include"
)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL3::SDL3)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm-header-only)

install(TARGETS BasicGraphics EXPORT BasicGraphicsTargets
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

install(EXPORT BasicGraphicsTargets
      FILE "BasicGraphicsTargets.cmake"
      NAMESPACE BasicGraphics::
      DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/BasicGraphics.cmake"
	DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/BasicGraphics"
)
