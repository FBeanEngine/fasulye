# Add source files
set(global_sources
    src/FUtils.cpp
)

# Add library target
add_library(Global ${global_sources})
target_link_libraries(Global PRIVATE raylib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Global PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)