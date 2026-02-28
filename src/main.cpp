#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void processInput(GLFWwindow* currentWindow);

void frameBufferSizeCallback(GLFWwindow* currentWindow, int width, int height)
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
    glClearColor(.25f, .25f, .25f, 1);

    std::cout << "Build succeeded!";

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}

void processInput(GLFWwindow* currentWindow)
{
    // Close Application
    if (glfwGetKey(currentWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(currentWindow, GLFW_KEY_BACKSPACE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(currentWindow, true);
    }

    // Background Color Switch
    else if (glfwGetKey(currentWindow, GLFW_KEY_R) == GLFW_PRESS) glClearColor(1, 0, 0, 1);
    else if (glfwGetKey(currentWindow, GLFW_KEY_G) == GLFW_PRESS) glClearColor(0, 1, 0, 1);
    else if (glfwGetKey(currentWindow, GLFW_KEY_B) == GLFW_PRESS) glClearColor(0, 0, 1, 1);
}