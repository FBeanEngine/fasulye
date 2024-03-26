# Add subdirectories
add_subdirectory(Player)
add_subdirectory(Scenes)

# Add source files
set(game_sources
    src/empty.cpp
)

# Add library target
add_library(Game ${game_sources})

# Include directories
target_link_libraries(Game PUBLIC Player Scenes Global)

target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)