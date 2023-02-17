#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "GAPIP/opengl/shader_interface.hpp"

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
                                                    -0.5f, 0.5f};

    const unsigned int num_faces = 2;
    unsigned int indices[num_faces*3] = {0, 1, 2,
                                         2, 3, 0 };

    // Modern OpenGL Vertex Buffer:
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, num_vertices * num_attributes * sizeof(float), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, num_attributes * sizeof(float), (const void*) 0);
    glEnableVertexAttribArray(0);

    // Modern OpenGL Index Buffer:
    unsigned int index_buffer;
    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_faces * 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Create OpenGL Program:
    unsigned int program = glCreateProgram();

    // Load the relevant shaders:
    GAPIP::add_shader(program, GL_VERTEX_SHADER, "shaders/opengl/vertex/basic_2d.shader");
    GAPIP::add_shader(program, GL_FRAGMENT_SHADER, "shaders/opengl/fragment/magenta.shader");

    glUseProgram(program);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Issue the draw call:
        glDrawElements(GL_TRIANGLES, 3 * num_faces, GL_UNSIGNED_INT, nullptr); // Using nullptr because index_buffer is already bound to GL_ELEMENT_ARRAY_BUFFER

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "hello!\n";
    return 0;
}