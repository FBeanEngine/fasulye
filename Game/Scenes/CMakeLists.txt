set(scene_sources
    src/FMainMenu.cpp
    src/FTestWorld.cpp
)

# Add library target
add_library(Scenes ${scene_sources})

add_dependencies(Scenes Base raylib)
target_link_libraries(Scenes PRIVATE raylib Base Global Manager Core Player)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Scenes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)