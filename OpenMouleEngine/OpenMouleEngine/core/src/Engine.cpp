////////////////////////////////////////////////////////////////////////
// Engine.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Engine.hpp"
#include "Camera.hpp"
#include "SceneGraph.hpp"
#include "ResourceManager.hpp"
#include <GL/glew.h>
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

        GLint maxTex;
        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxTex);
        std::cout << "Maximum texture units: " << maxTex << std::endl;

        // camera
        camera = new CameraPerspective(60, 4/3.f, 0.1f, 1000);
        
        // Shaders et mesh
        rm = ResourceManager::getInstance();
        sg = SceneGraph::getInstance();

        // OpenGL initialisation
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glEnable(GL_ALPHA_TEST);
        //glEnable(GL_BGR_EXT);
        //glAlphaFunc(GL_GREATER, 0.1);

        // point sprites
        glEnable(GL_POINT_SPRITE);
        glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
        glTexEnvi(GL_POINT_SPRITE,  GL_COORD_REPLACE, GL_TRUE);
        glPointSize(64);
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
