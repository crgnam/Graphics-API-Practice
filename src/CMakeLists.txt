# Add my_opengl:
if (BUILD_OPENGL)
	find_package(OpenGL REQUIRED)
	find_package(glfw3 CONFIG REQUIRED)
	find_package(glew CONFIG REQUIRED)
	add_executable(my_opengl my_opengl.cpp)
	target_link_libraries(my_opengl glfw GLEW::GLEW opengl32)
endif()

# Add my_vulkan:
if (BUILD_VULKAN)
	message("VULKAN DEMO APPLICATION IS NOT YET IMPLEMENTED")
endif()

# Add my_opencl:
if (BUILD_OPENCL)
	message("OPENCL DEMO APPLICATION IS NOT YET IMPLEMENTED")
endif()

# Add my_optix:
if (BUILD_OPTIX)
	message("OptiX DEMO APPLICATION IS NOT YET IMPLEMENTED")
endif()