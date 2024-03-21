set(player_sources
    src/FAmmo.cpp
    src/FGun.cpp
    src/FPlayer.cpp
)

# Add library target
add_library(Player ${player_sources})

# Include directories
target_include_directories(Player PUBLIC include)