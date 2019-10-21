cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(console-generator
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "A code genrator for the console-component, it generate commands quickly, so you can be more productive and focus only on code."
)

# Set All Required Filesystem Linking
if(APPLE)
  set(FILESYSTEM_CXX -lc++fs)
elseif(MSVC)
  #
else()
  set(FILESYSTEM_CXX -lstdc++fs)
endif()

# Collect Implemention Files Of The Current Project
set(SOURCES_CXX_FILES
    main.cpp
    commands/make_command.cpp
)

# Add The Implemention Files To The Executable
add_executable(${PROJECT_NAME} ${SOURCES_CXX_FILES})

# Add The Definition Files
include_directories(${CMAKE_BINARY_DIR}/dist/include)

# Link The Executable With The Library
target_link_libraries(${PROJECT_NAME} console ${FILESYSTEM_CXX})