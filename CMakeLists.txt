cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(console-generator
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "A code genrator for the console-component, it generate commands quickly, so you can be more productive and focus only on code."
)

# Link libraries statically
set(BUILD_SHARED_LIBS OFF)

# Support only from CPP-17 standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Link libraries statically
set(BUILD_SHARED_LIBS OFF)

# Set the parallel jobs
set(CMAKE_BUILD_PARALLEL_LEVEL 4)

# Add The CPM Package Manager
if(NOT EXISTS "${CMAKE_HOME_DIRECTORY}/cmake/CPM.cmake")
  file(DOWNLOAD https://raw.githubusercontent.com/TheLartians/CPM.cmake/master/cmake/CPM.cmake "${CMAKE_HOME_DIRECTORY}/cmake/CPM.cmake")
endif()

include(cmake/CPM.cmake)

# Add The console-component
CPMAddPackage(
  NAME console
  GITHUB_REPOSITORY edenreich/console-component
  VERSION 1.0.3
  OPTIONS
    "WITH_TESTS Off"
)

# Move The Default Directory Of The Executable To bin Directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/bin)

add_subdirectory(src)
