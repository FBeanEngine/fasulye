cmake_minimum_required(VERSION 3.20)
project(fasulye)

set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

# Dependencies
include(FetchContent)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

add_subdirectory(Global)

# Add Core directory
add_subdirectory(Core)

# Add Game directory
add_subdirectory(Game)


# Define project sources
set(PROJECT_SOURCES main.cpp)

# Add executable target
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} Global Core Game raylib)

# Copy resources to binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/resources)
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources
        COMMENT "Copying resources into binary directory")

add_dependencies(${PROJECT_NAME} copy_resources)


# Additional settings for macOS
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()