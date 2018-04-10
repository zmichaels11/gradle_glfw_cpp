#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

int main(int argc, char ** argv) {
    if (!glfwInit()) {
        throw std::runtime_error("Unable to initialize GLFW!");
    }

    auto window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);

    if (window == nullptr) {
        throw std::runtime_error("Unable to create GLFW window!");
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}