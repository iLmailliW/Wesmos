#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int screen_width = 800;
int screen_height = 600;

GLFWwindow* createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, "Wesmos", NULL, NULL);
    if (!window) 
    {
        std::cout << "Error: failed to create GLFW window" << std::endl;
        return NULL;
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowAspectRatio(window, 4, 3);
    return window;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(){
    
    GLFWwindow* window = createWindow();
    if (!window) return 1;

    // Pass GLAD the function pointer it needs
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Error: Failed to initialize GLAD" << std::endl;
        return 1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window))
    {

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}