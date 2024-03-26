set(player_sources
    src/FAmmo.cpp
    src/FGun.cpp
    src/FPlayer.cpp
    src/FItem.cpp
)

# Add library target
add_library(Player ${player_sources})

add_dependencies(Player Base raylib Manager)
target_link_libraries(Player PRIVATE raylib Base Manager Global Animation Core)

# Include directories
Include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)