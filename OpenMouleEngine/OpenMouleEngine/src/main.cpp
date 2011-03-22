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
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
    //glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Open an OpenGL window
    if (!glfwOpenWindow(640, 480, 8, 8, 8, 8, 32, 0, GLFW_WINDOW))
    {
        cout << "Error: glfwOpenWindow() failed" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowTitle("OpenMouleEngine");
}

#pragma comment(lib, "glu32.lib")
void errorCheck()
{
    GLenum err = glGetError();
    if(err != GL_NO_ERROR)
        cout << gluErrorString(err) << endl;
    else
        cout << "Jusqu'ici, tout va bien..." << endl;
}


int main(void)
{
    makeWindow();

    Engine *engine = Engine::getInstance();
    ResourceManager *rm = ResourceManager::getInstance();
    SceneGraph *sg = SceneGraph::getInstance();

    // setting loaders
    rm->add(new VertexShaderLoader(), "vert");
    rm->add(new FragmentShaderLoader(), "frag");
    rm->add(new ObjLoader(), "obj");
    rm->add(new MeshLoader(), "msh");
    rm->add(new DevILLoader(), "png");

    // setting savers
    rm->add(new MeshSaver(), "msh");

    // creating a mesh
    Mesh *mesh;
    double t;

    t = glfwGetTime();
    mesh = rm->getMesh("data/obj/smooth.obj");
    cout << "Temps de chargement du .obj: " << glfwGetTime() - t << " secondes." << endl;

    mesh->centerPivot();
    mesh->saveAs("test.msh");

    t = glfwGetTime();
    //mesh = 
        rm->getMesh("test.msh");
    cout << "Temps de chargement du .msh: " << glfwGetTime() - t << " secondes." << endl;

    ShaderProgram shader("data/shaders/basic.vert", "data/shaders/basic.frag");
    shader.link();
    mesh->setShader(&shader);
    sg->add(*mesh);

    Texture *texture = rm->getTexture("data/textures/grass.png");
    mesh->setTexture(texture);

    CameraPerspective *cam = dynamic_cast<CameraPerspective *>(engine->getCamera());
 
    // main loop
    bool running = true;
    bool centered = false;
    float theta = 0;
    float phi = M_PI / 4;
    glfwSetMouseWheel(-10000);
    
    while(running)
    {
        // check for exit
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
        
        // angles update
        if(glfwGetKey(GLFW_KEY_UP))
            phi += 0.02f;
        else if(glfwGetKey(GLFW_KEY_DOWN))
            phi -= 0.02f;
        if(glfwGetKey(GLFW_KEY_LEFT))
            theta -= 0.02f;
        else if(glfwGetKey(GLFW_KEY_RIGHT))
            theta += 0.02f;

        if(!centered && glfwGetKey(GLFW_KEY_SPACE))
            mesh->centerPivot();

        // avoid camera being upside down
        if(phi > (M_PI / 2.f - 0.01f))
            phi = M_PI / 2.f - 0.01f;

        if(phi < (-M_PI / 2.f + 0.01f))
            phi = -M_PI / 2.f + 0.01f;

        // avoid negative zoom
        if(glfwGetMouseWheel() >= 0)
            glfwSetMouseWheel(-1);

        // camera update
        cam->lookAt(vec3(
            cos(phi) * cos(theta),              // x
            cos(phi) * sin(theta),              // y
            sin(phi))                           // z
            * (-glfwGetMouseWheel() / 20.f));   // zoom
        
        // display
        engine->clearColorBuffer();
        engine->clearDepthBuffer();
        engine->render();

        glfwSwapBuffers();
        glfwSleep(0.016);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
