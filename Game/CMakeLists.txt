# Include Player
add_subdirectory(Player)
# Include Scenes
add_subdirectory(Scenes)

# Add source files
set(game_sources
    src/FItem.cpp
)

# Add library target
add_library(Game ${game_sources})

# Include directories
target_include_directories(Game PUBLIC include)