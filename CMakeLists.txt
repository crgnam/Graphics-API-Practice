cmake_minimum_required(VERSION 3.9)
project(gpu_practice LANGUAGES CXX VERSION 0.9)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE) 
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Uncomment these lines to compile for debugging:
# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS_DEBUG "-g")

option(BUILD_OPENGL "Build the OpenGL Demo" TRUE)
option(BUILD_VULKAN "Build the Vulkan Demo" TRUE)
option(BUILD_OPENCL "Build the OpenCL Demo" TRUE)
option(BUILD_OPTIX  "Build the OptiX Demo"  TRUE)

# Check the OS:
if(MSVC OR MINGW)
  # If on Windows:

elseif(UNIX AND NOT APPLE)
  # If on Linux:
  set(CMAKE_CXX_FLAGS "-Wall -mtune=native -march=native -g")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fno-math-errno -fno-signed-zeros -fno-trapping-math -freciprocal-math -fno-rounding-math -fno-signaling-nans -fexcess-precision=fast")

elseif(APPLE)
  # In on Apple:

endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include system installed libraries:
include(InstallRequiredSystemLibraries)

# Add the included directories:
include_directories(include)

# Add project subdirectories:
add_subdirectory(lib)
add_subdirectory(src)

# Copy the shaders to the build directory:
file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)

# Setup Installation instructions:
install(DIRECTORY shaders/ DESTINATION bin/shaders)


# Use CPack to generate Installer:
# include(installrequiredsystemlibraries)
# set(cpack_resource_file_license "")
# set(cpack_package_version_major "")
# set(cpack_package_version_minor "")
# include(cpack)