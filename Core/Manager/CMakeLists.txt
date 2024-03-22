set(manager_sources
    src/FCamera.cpp
    src/FCanvas.cpp
    src/FInputManager.cpp
    src/FSceneManager.cpp
)

# Add library target
add_library(Manager ${manager_sources})

# Include directories
target_include_directories(Manager PUBLIC include)