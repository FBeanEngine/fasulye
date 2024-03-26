# Add subdirectories
add_subdirectory(Animation)
add_subdirectory(Base)
add_subdirectory(Manager)

# Add source files
set(core_sources
    src/FGame.cpp
    src/FGrid.cpp
    src/FShader.cpp
)

# Add library target
add_library(Core ${core_sources})

# Include directories
target_link_libraries(Core PUBLIC Animation Base Manager Scenes)

add_dependencies(Core raylib Global)
target_link_libraries(Core PRIVATE raylib Global Player)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)