#ifndef INPUT
#define INPUT

#include "GLFW/glfw3.h"

void inline process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

#endif // !INPUT
