set(base_sources
    src/FObject.cpp
    src/FScene.cpp
    src/FUI.cpp
)

# Add library target
add_library(Base ${base_sources})

# Include directories
target_include_directories(Base PUBLIC include)