#include <GL/glfw.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int running = GL_TRUE;
    int major, minor, rev;
    
    if (!glfwInit()) 
    {
        puts("merde 1");
        exit(EXIT_FAILURE);
    }
    
    glfwGetVersion(&major, &minor, &rev);
    printf("GLFW %d.%d rev %d\n", major, minor, rev);
    printf("%d CPUs detected\n", glfwGetNumberOfProcessors());
    
    // Open an OpenGL window
    if (!glfwOpenWindow(300, 300, 8, 8, 8, 8, 8, 0, GLFW_WINDOW))
    {
        puts("Error: glfwOpenWindow() failed");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    printf("OpenGL: %s\n", glGetString(GL_VERSION));
    printf("Hardware: %s (%s)\n", glGetString(GL_RENDERER), glGetString(GL_VENDOR));

    while(running) 
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers();
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    
    glfwTerminate();

    exit(EXIT_SUCCESS);
}

