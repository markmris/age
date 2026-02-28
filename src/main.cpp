#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void processInput(GLFWwindow* window);

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Initialize
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 1920;
    int height = 1080;

    GLFWwindow* window = glfwCreateWindow(width, height, "AGE", NULL, NULL);

    if (!window)
    {
        std::cout << "Failed to create GLFW window. Terminating program...\n";
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load GLAD. Terminating program...";

        return -1;
    }
    
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(.5f, .5f, .5f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}

void processInput(GLFWwindow* window)
{
    // Close Application
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_BACKSPACE))
    {
        glfwSetWindowShouldClose(window, true);
    }
}