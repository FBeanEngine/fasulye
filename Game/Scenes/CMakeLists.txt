set(scene_sources
    src/FMainMenu.cpp
    src/FTestWorld.cpp
)

# Add library target
add_library(Scenes ${scene_sources})

# Include directories
target_include_directories(Scenes PUBLIC include)