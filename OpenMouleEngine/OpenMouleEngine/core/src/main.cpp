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
    if (!glfwOpenWindow(640, 480, 8, 8, 8, 8, 0, 0, GLFW_WINDOW))
    {
        cout << "Error: glfwOpenWindow() failed" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowTitle("OpenMouleEngine");
}


//#pragma comment(lib, "glu32.lib")
//void errorCheck()
//{
//    GLenum err = glGetError();
//    if(err != GL_NO_ERROR)
//        cout << gluErrorString(err) << endl;
//    else
//        cout << "Jusqu'ici, tout va bien..." << endl;
//}


void makeGrid(int size, int pitch)
{
    std::vector<vec3> *positions = new std::vector<vec3>();
    std::vector<Color> *colors = new std::vector<Color>();

    int begin = -size / 2;
    int end = size / 2;

    for(int i = begin; i <= end; i += pitch)
    {
        // X axis
        positions->push_back(vec3(i, begin));
        positions->push_back(vec3(i, end));

        // Y axis
        positions->push_back(vec3(begin, i));
        positions->push_back(vec3(end, i));

        // colors
        for(int j = 0; j < 4; j++)
        {
            if(i == 0)
                colors->push_back(Color(0, 0, 0));
            else
                colors->push_back(Color(0.3f, 0.3f, 0.3f));
        }
    }

    // creating vertex arrays
    VertexArray *va = new VertexArray("a_Vertex", positions);
    va->addSubArray("a_Color", colors);

    MeshData *md = new MeshData("grid", va);
    Mesh *m = md->getMesh();

    ShaderProgram *shader = new ShaderProgram("data/shaders/grid.vert", "data/shaders/grid.frag");
    shader->link();
    m->setShader(shader);
    m->setRenderMode(GL_LINES);
    SceneGraph::getInstance()->add(*m);
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
    rm->add(DevILLoader::getInstance(), "jpg");
    rm->add(DevILLoader::getInstance(), "png");
    rm->add(new MeshLoader(), "msh");
    rm->add(new MD2Loader(), "md2");

    // setting savers
    rm->add(new MeshSaver(), "msh");

    makeGrid(100, 10);

    /*Mesh *mesh = rm->getMesh("data/obj/chamfer.obj");
    ShaderProgram shader("data/shaders/basic.vert", "data/shaders/basic.frag");
    shader.link();
    mesh->setShader(&shader);
    Material material("smbCube");
    material.setDiffuse(rm->getTexture("data/textures/smb3.png"));
    material.setShininess(32.f);
    mesh->setMaterial(&material);
    mesh->translate(vec3(0, -25));
    sg->add(*mesh);

    //rm->saveAs(*mesh->data(), "test.msh");

    Mesh *mesh2 = rm->getMesh("data/obj/chamfer.obj");
    ShaderProgram shader2("data/shaders/point.vert", "data/shaders/point.frag");
    shader2.link();
    mesh2->setShader(&shader2);
    Material material2("pointSprite");
    material2.setDiffuse(rm->getTexture("data/textures/particle.png"));
    mesh2->setMaterial(&material2);
    mesh2->translate(vec3(0, 25));
    mesh2->setRenderMode(GL_POINTS);
    mesh2->setPointSize(100);
    sg->add(*mesh2);*/

    CameraPerspective *cam = dynamic_cast<CameraPerspective *>(engine->getCamera());

    // main loop
    bool running = true;
    float theta = 0;
    float phi = PI / 4.f;
    glfwSetMouseWheel(-100);

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

        //if(glfwGetKey(GLFW_KEY_SPACE))
            //mesh->rotate(vec3(1, 2, 3));

        // avoid camera being upside down
        if(phi > (PI / 2.f - 0.01f))
            phi = PI / 2.f - 0.01f;

        if(phi < (-PI / 2.f + 0.01f))
            phi = -PI / 2.f + 0.01f;

        // avoid negative zoom
        if(glfwGetMouseWheel() > -1)
            glfwSetMouseWheel(-1);

        // camera update
        vec3 camPos(cos(phi) * cos(theta), cos(phi) * sin(theta), sin(phi));
        cam->lookAt(camPos * (glfwGetMouseWheel() * glfwGetMouseWheel() * 0.01f));

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
