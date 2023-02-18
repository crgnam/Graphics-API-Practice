if (BUILD_OPENGL)
	add_library(libmy_opengl STATIC
		opengl/shader_interface.cpp
		opengl/utils.cpp
		opengl/vertex_array.cpp
		opengl/vertex_buffer.cpp
		opengl/index_buffer.cpp
		opengl/renderer.cpp
	)
	find_package(OpenGL REQUIRED)
	find_package(glfw3 CONFIG REQUIRED)
	find_package(glew CONFIG REQUIRED)
	target_link_libraries(libmy_opengl PUBLIC glfw GLEW::GLEW OpenGL::GL)

	INSTALL(TARGETS libmy_opengl DESTINATION bin)

	install(IMPORTED_RUNTIME_ARTIFACTS glfw GLEW::GLEW)
endif()