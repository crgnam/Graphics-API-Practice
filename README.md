# Graphics API Practice
This project is intended to serve as basic practice of various graphics (and GPU Compute) APIs.  Namely OpenGL, Vulkan, OptiX and OpenCL.  The purpose of this exercise is to learn enough about how a GPU functions as to properly frame the internal data structures of Vira, my (soon to be) opensource rendering engine.

## Building:
This project uses CMake to generate the build system and vcpkg to install all dependencies.  Please make sure both are properly installed on your machine.

**CMake Options:**
- `BUILD_OPENGL`: Builds `my_opengl` test application.  This defaults to `TRUE`
- `BUILD_VULKAN`: Builds the `my_vulkan` test application (*NOT YET COMPLETED*).  This defaults to `TRUE`.
- `BUILD_OPENCL`: Builds the `my_opencl` test application (*NOT YET COMPLETED*).  This defaults to `TRUE`.
- `BUILD_OPTIX` : Builds the `my_optix` test application (*NOT YET COMPLETED*).  This defaults to `TRUE`.

### Windows with Visual Studio:
Simply allow the CMake configuration to complete and then Build usingby selecting from the top toolbar: `Build->Build All`.

### Linux:
```
mkdir build
cd build
cmake ..
cmake --build . -j
```

### MacOS:
```
mkdir build
cd build
cmake ..
cmake --build . -j
```