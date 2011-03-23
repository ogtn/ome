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
            std::cerr << "Error: glewInit() failed: " << glewGetErrorString(err) << std::endl;
        
        std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

        // a few prints
        std::cout << "Software: OpenGL " << glGetString(GL_VERSION) << std::endl;
        std::cout << "Hardware: " << glGetString(GL_RENDERER);
        std::cout << " (" << glGetString(GL_VENDOR) << ")" << std::endl;

        // camera
        camera = new CameraPerspective(70, 4/3.f, 0.1f, 1000);
        
        // Shaders et mesh
        rm = ResourceManager::getInstance();
        sg = SceneGraph::getInstance();

        // OpenGL initialisation
        glEnable(GL_DEPTH_TEST);
        //glEnable(GL_BLEND);
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glEnable(GL_ALPHA_TEST);

        //glEnable(GL_TEXTURE_2D);
        //glEnable(GL_BGR_EXT);
        //glEnable(GL_ALPHA_TEST);
        //glEnable(GL_BLEND);
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glAlphaFunc(GL_GREATER, 0.1);
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


    void Engine::clearDepthBuffer()
    {
        glClear(GL_DEPTH_BUFFER_BIT);
    }


    Camera *Engine::getCamera()
    {
        return camera;
    }
} // namespace
