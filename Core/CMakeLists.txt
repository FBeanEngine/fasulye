# Include Animation
add_subdirectory(Animation)
# Include Base
add_subdirectory(Base)
# Include Managers
add_subdirectory(Manager)

# Add source files
set(core_sources
    src/FGame.cpp
    src/FGrid.cpp
    src/FShader.cpp
    src/utils.cpp
)

# Add library target
add_library(Core ${core_sources})

# Include directories
target_include_directories(Core PUBLIC include)
