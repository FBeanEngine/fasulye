set(animation_sources
    src/FAnimation.cpp
    src/FAnimationClip.cpp
)

# Add library target
add_library(Animation ${animation_sources})

add_dependencies(Animation raylib)
target_link_libraries(Animation PRIVATE raylib)

# Include directories
target_include_directories(Animation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)