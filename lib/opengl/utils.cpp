#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GAPIP/opengl/utils.hpp"

void GAPIP::GLClearError() {
    while (glGetError() != GL_NO_ERROR) {

    };
};

bool GAPIP::GLLogCall(const char* function, const char* file, int line) {
    bool no_errors = true;
    while (GLenum error = glGetError()) { // Loop while error is not 0 (GL_NO_ERROR)
        std::cout << "[OpenGL Error] (" << error << "): " << function <<
                     " " << file << ":" << line << std::endl;
        no_errors = false;
    };
    return no_errors;
};
