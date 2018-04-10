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

    {
        auto err = glewInit();

        if (GLEW_OK != err) {
            auto errmsg = glewGetErrorString(err);

            throw std::runtime_error(reinterpret_cast<const char * > (errmsg));
        }
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION)
        << "\nOpenGL Renderer: " << glGetString(GL_RENDERER)
        << "\nOpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
        << std::endl;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}