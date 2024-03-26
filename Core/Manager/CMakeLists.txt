set(manager_sources
    src/FCamera.cpp
    src/FCanvas.cpp
    src/FInputManager.cpp
    src/FSceneManager.cpp
)

# Add library target
add_library(Manager ${manager_sources})

add_dependencies(Manager raylib Global)
target_link_libraries(Manager PRIVATE raylib Core Global)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_include_directories(Manager PRIVATE $<TARGET_PROPERTY:Global,INTERFACE_INCLUDE_DIRECTORIES>)
target_include_directories(Manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)