#ifndef INIT_WINDOW
#define INIT_WINDOW

#include <GLFW/glfw3.h>
#include <stdio.h>

inline bool init_window(GLFWwindow **window) 
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    *window = glfwCreateWindow(800, 600, "Hello OpenGL!", NULL, NULL);
    if (*window == NULL) {
        printf("Failed to create glfw window!\n");
        return false;
    }
    glfwMakeContextCurrent(*window);

    return true;
}

/**
 * Custom callback for setting the gl viewport whenever the user 
 * resizes the window.
 * @param window Pointer to the window containing the gl context.
 * @param width Width to pass to glViewport.
 * @param height Height to pass to glViewport.
 * */
void inline framebuffer_size_callback([[maybe_unused]]GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

#endif // !INIT_WINDOW
