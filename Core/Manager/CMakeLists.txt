set(manager_sources
    src/FObject.cpp
    src/FScene.cpp
    src/FUI.cpp
)

# Add library target
add_library(Manager ${manager_sources})

# Include directories
target_include_directories(Manager PUBLIC include)