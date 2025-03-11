cmake_minimum_required(VERSION 3.10)
project(Shape)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Source files
set(SOURCES
    main.cpp
    src/MyCircle.cpp
    src/MyRoundedRectangle.cpp
    src/MyRoundedOutlinedRectangle.cpp
)

# Header files
set(HEADERS
    include/MyCircle.h
    include/MyRoundedRectangle.h
    include/MyRoundedOutlinedRectangle.h
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)
