#include "OpenMouleEngine.hpp"
#include <GL/glfw.h>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    int running = GL_TRUE;
    int major, minor, rev;
    
    if (!glfwInit()) 
    {
        cout << "Error: glfwInit() failed" << endl;
        exit(EXIT_FAILURE);
    }
    
    glfwGetVersion(&major, &minor, &rev);
    cout << "GLFW " << major << "." << minor << " rev " << rev << endl;
    cout << glfwGetNumberOfProcessors() << " CPUs detected" << endl; 
    
    // Open an OpenGL window
    if (!glfwOpenWindow(500, 500, 8, 8, 8, 8, 8, 0, GLFW_WINDOW))
    {
        cout << "Error: glfwOpenWindow() failed" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowTitle("OpenMouleEngine");
    ome::Engine engine;
    
    while(running) 
    {
        engine.clearColorBuffer();
        engine.render();

        glfwSwapBuffers();
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
