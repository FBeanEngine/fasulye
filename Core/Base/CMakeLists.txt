set(base_sources
    src/FObject.cpp
    src/FScene.cpp
    src/FUI.cpp
)

# Add library target
add_library(Base ${base_sources})

add_dependencies(Base raylib Global Manager)
target_link_libraries(Base PRIVATE raylib Core Global Manager)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(Base PRIVATE $<TARGET_PROPERTY:Manager,INTERFACE_INCLUDE_DIRECTORIES>)
target_include_directories(Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)