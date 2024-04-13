cmake_minimum_required(VERSION 3.21)
project(MonteCarlo)

# Set Geant4_DIR to the path where Geant4Config.cmake is located.
# It should be in the 'lib/CMake/Geant4' directory of the Geant4 installation.
set(Geant4_DIR C:/Users/chaha/OneDrive/Desktop/geant4/geant4-v11/progs/lib/CMake/Geant4)

# Find the Geant4 package, specifying that UI and visualization drivers are needed.
find_package(Geant4 REQUIRED ui_all vis_all)

# Set up Geant4 include directories and compile definitions.
include(${Geant4_USE_FILE})

# Include the project directory for header files.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Set the output directory for executables and libraries.
# This is where the compiled application will be placed.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Define the source and header files for the executable.
add_executable(MonteCarlo
        MonteC.cpp
        MonteC.h)

# Link the executable to the Geant4 libraries.
target_link_libraries(MonteCarlo ${Geant4_LIBRARIES})

# The paths for Geant4_INCLUDE_DIR and Geant4_LIBRARY_DIR are automatically set by find_package command.
