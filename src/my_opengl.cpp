#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "GAPIP/opengl/vertex_array.hpp"
#include "GAPIP/opengl/vertex_buffer.hpp"
#include "GAPIP/opengl/vertex_buffer_layout.hpp"
#include "GAPIP/opengl/index_buffer.hpp"
#include "GAPIP/opengl/shader_interface.hpp"
#include "GAPIP/opengl/utils.hpp"

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    };

    #ifdef __APPLE__
        std::cout << "I'm apple machine" << std::endl;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    /* Create a windowed mode window and its OpenGL context */
    unsigned int width = 800;
    unsigned int height = 600;
    window = glfwCreateWindow(width,height, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize GLEW:
    if (glewInit() != GLEW_OK) {
        std::cout << "Error!\n";
    };

    // Create vertex buffer:
    const unsigned int num_vertices = 4;
    const unsigned int num_attributes = 2;
    float positions[num_vertices*num_attributes] = {-0.5f, -0.5f,
                                                     0.5f, -0.5f,
                                                     0.5f,  0.5f,
                                                    -0.5f,  0.5f};

    const unsigned int num_faces = 2;
    unsigned int indices[num_faces*3] = {0, 1, 2,
                                         2, 3, 0 };

    // Vertex buffer:
    VertexBuffer vb(positions, num_vertices * num_attributes * sizeof(float));

    // Vertex buffer layout:
    VertexBufferLayout layout;
    layout.push<float>(2);

    // Vertex array:
    VertexArray va;
    va.add_buffer(vb, layout);

    // Index Buffer:
    IndexBuffer ib(indices, 3*num_faces);

    // Create OpenGL Program:
    unsigned int program = glCreateProgram();

    // Load the relevant shaders:
    GAPIP::add_shader(program, GL_VERTEX_SHADER, "shaders/opengl/vertex/basic_2d.shader");
    GAPIP::add_shader(program, GL_FRAGMENT_SHADER, "shaders/opengl/fragment/magenta.shader");

    // Tell GL to use the program the shaders are bound to:
    GLCall(glUseProgram(program));

    // Create uniform:
    GLCall(int location = glGetUniformLocation(program, "u_Color"));
    ASSERT(location != -1)
    
    // Initial color:
    float r = 1;
    float b = 1;
    float g = 0;
    float rb_step = -0.01;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        GLCall(glUseProgram(program));

        if (r > 1.0f || r < 0.0f) {
            rb_step = -rb_step;
        }
        r = r + rb_step;
        b = b + rb_step;
        g = g - rb_step;
        GLCall(glUniform4f(location, r, g, b, 1.0f));

        va.bind();
        ib.bind();

        // Issue the draw call:
        GLCall(glDrawElements(GL_TRIANGLES, 3 * num_faces, GL_UNSIGNED_INT, nullptr)); // Using nullptr because index_buffer is already bound to GL_ELEMENT_ARRAY_BUFFER

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "hello!\n";
    return 0;
}