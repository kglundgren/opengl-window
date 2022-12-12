#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "glad/glad.h"
#pragma GCC diagnostic pop

#include "GLFW/glfw3.h"

#include <windows.h>
#include <gl/GL.h>
#include <stdio.h>

#include "window/init_window.h"
#include "input/input.h"

int main (int argc, char *argv[])
{
    if (argc >= 2) {
        printf("Hello, %s! Welcome to OpenGL.\n", argv[1]);
    } else {
        printf("Hello, world! Welcome to OpenGL.\n");
    }

    glfwInit();

    GLFWwindow *window;
    if (!init_window(&window)) {
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD!\n");
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)) {
        // Input.
        process_input(window);

        // Render.
        glClearColor(0.0f, 0.6f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers and poll events.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
