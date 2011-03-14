#include "OpenMouleEngine.hpp"
#include <GL/glfw.h>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using namespace ome;

void makeWindow()
{
    int major, minor, rev;

    if (!glfwInit()) 
    {
        cout << "Error: glfwInit() failed" << endl;
        exit(EXIT_FAILURE);
    }

    glfwGetVersion(&major, &minor, &rev);
    cout << "GLFW " << major << "." << minor << " rev " << rev << endl;
    cout << glfwGetNumberOfProcessors() << " CPUs detected" << endl; 

    //forward compatibility OpenGL 3.3
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Open an OpenGL window
    if (!glfwOpenWindow(500, 500, 8, 8, 8, 8, 24, 0, GLFW_WINDOW))
    {
        cout << "Error: glfwOpenWindow() failed" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowTitle("OpenMouleEngine");
}


int main(void)
{
    makeWindow();

    Engine *engine = Engine::getInstance();
    ResourceManager *rm = ResourceManager::getInstance();
    SceneGraph *sg = SceneGraph::getInstance();

    // setting loaders
    rm->add(new DefaultVertexShader(), "vert");
    rm->add(new DefaultFragmentShader(), "frag");
    rm->add(new DefaultMesh(), "mesh");
    rm->add(new ObjLoader(), "obj");

    // creating a mesh
    Mesh *mesh = rm->getMesh("data/obj/2plans.obj");
    ShaderProgram shader("", "");
    shader.link();
    mesh->setShader(&shader);
    sg->add(*mesh);

    // main loop
    bool running = true;

    while(running) 
    {
        // events
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
        
        // display
        engine->clearColorBuffer();
        engine->render();
        glfwSwapBuffers();
        glfwSleep(0.016);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
