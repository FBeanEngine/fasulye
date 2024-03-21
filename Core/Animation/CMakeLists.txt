set(animation_sources
    src/FAnimation.cpp
    src/FAnimationClip.cpp
)

# Add library target
add_library(Animation ${animation_sources})

# Include directories
target_include_directories(Animation PUBLIC include)