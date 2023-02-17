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
        cout << "I'm apple machine" << endl;
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
    float positions[6] = {-0.5f, -0.5f,
                           0.0f,  0.5f,
                           0.5f, -0.5f};

    // Modern OpenGL Vertex Buffer:
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*) 0);
    glEnableVertexAttribArray(0);

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
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "hello!\n";
    return 0;
}