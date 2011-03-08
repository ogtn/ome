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
        
        // Shaders
        rm = ResourceManager::getInstance();
        rm->add(new DefaultVertexShader(), "vert");
        rm->add(new DefaultFragmentShader(), "frag");
        rm->add(new DefaultMesh(), "mesh");
        Shader *vertShader = rm->getShader("shader.vert");
        Shader *fragShader = rm->getShader("shader.frag");
        mesh = rm->getMesh("monMesh.mesh");
        shader = new ShaderProgram(vertShader, fragShader);
        vertShader->compile();
        fragShader->compile();
        shader->link();

        sg = SceneGraph::getInstance();
        sg->add(*mesh);
    }

    
    Engine::~Engine()
    {
        delete shader;
    }
    

    Engine &Engine::render()
    {
        shader->bind();
        shader->sendUniform("projection", projection);
        shader->sendUniform("modelview", modelview);
        mesh->render();
        shader->unbind();
       
        return *this;
    }


    Engine &Engine::clearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        return *this;
    }
} // namespace
