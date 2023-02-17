#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GAPIP/opengl/shader_interface.hpp"

// Load a shader code:
std::string load_shader_source(const std::string& file_path) {
    std::ifstream source_file(file_path);
    if (source_file.fail()) {
        std::cout << "Specified file (" << file_path << ") does not exist!\n";
    }

    std::stringstream source;
    source << source_file.rdbuf();

    return source.str();
};

// Compile a given shader:
static unsigned int compile_shader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Error handling:
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));

        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile shader!  GL Log:\n";
        std::cout << message << "\n";

        glDeleteShader(id);
        return 0;  // Gross
    };

    return id;
};

// Static function:
void GAPIP::add_shader(unsigned int program, unsigned int type, const std::string& shader_path) {
    auto shader_source = load_shader_source(shader_path);

    unsigned int shader = compile_shader(type, shader_source);

    glAttachShader(program, shader);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(shader);
};