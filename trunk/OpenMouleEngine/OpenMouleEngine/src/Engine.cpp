////////////////////////////////////////////////////////////////////////
// Engine.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Engine.hpp"
#include <iostream>

namespace OpenMouleEngine
{
    Engine::Engine()
    {
        // glew initialisation
        GLenum err = glewInit();

        if(err != GLEW_OK)
            std::cout << "Error: glewInit() failed: " << glewGetErrorString(err) << std::endl;
        
        std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

        // a few prints
        std::cout << "Software: OpenGL " << glGetString(GL_VERSION) << std::endl;
        std::cout << "Hardware: " << glGetString(GL_RENDERER);
        std::cout << " (" << glGetString(GL_VENDOR) << ")" << std::endl;

        // OpenGL initialisation
        projection.makeOrtho(0, 1, 0, 1, -1, 1);
        projection.makePerspective(70, 1, 0.1, 1000);
        modelview.lookAt(vec3(1, 1, 1));
        
        // Shaders et mesh
        rm = ResourceManager::getInstance();
        sg = SceneGraph::getInstance();
    }

    
    Engine::~Engine()
    {
    }
    

    void Engine::render()
    {
        sg->renderAll();
    }


    void Engine::clearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }


    mat4 &Engine::getProjection()
    {
        return projection;
    }


    mat4 &Engine::getModelView()
    {
        return modelview;
    }
} // namespace
