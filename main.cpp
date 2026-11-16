#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shaderprogram.h>
#include <projection.h>
#include <ast.h>
#include <lexer.h>
#include <parser.h>
#include <graph.h>

constexpr int INITIAL_SCREEN_WIDTH = 800;
constexpr int ASPECT_X = 4;
constexpr int ASPECT_Y = 3;

constexpr int LOD = 8;

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

GLFWwindow* createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    float screen_height = (float) INITIAL_SCREEN_WIDTH * (float) ASPECT_Y / (float) ASPECT_X;
    GLFWwindow* window = glfwCreateWindow(INITIAL_SCREEN_WIDTH, (int) screen_height, "Wesmos", NULL, NULL);
    if (!window)
    {
        std::cout << "Error: failed to create GLFW window" << std::endl;
        return NULL;
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowAspectRatio(window, ASPECT_X, ASPECT_Y);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetKeyCallback(window, keyCallback);

    return window;
}


int main(){

    float vertices[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
    };

    int indices[] = {
        0, 1, 2
    };
    
    GLFWwindow* window = createWindow();
    if (!window) return 1;

    // Pass GLAD the function pointer it needs
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Error: Failed to initialize GLAD" << std::endl;
        return 1;
    }

    glViewport(0, 0, 800, 600);
    glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    ShaderProgram program = ShaderProgram("shader/vertex/default.glsl", "shader/fragment/default.glsl");
    program.use();

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexArrayAttrib(VAO, 0);
    
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        program.use();

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glm::mat4x4 mat = projection::GetVertexMatrix(width, height, glfwGetTime() / 10, projection::PI / 4.0f, 5.0f);

        int location = glGetUniformLocation(program.ID, "myMat");
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}