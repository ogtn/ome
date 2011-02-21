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
        // a few prints
        std::cout << "Software: OpenGL " << glGetString(GL_VERSION) << std::endl;
        std::cout << "Hardware: " << glGetString(GL_RENDERER);
        std::cout << " (" << glGetString(GL_VENDOR) << ")" << std::endl;

        // OpenGL initialisation
        Mat4f projection, modelview;
        glMatrixMode(GL_PROJECTION);
        projection.load();
        glOrtho(0, 500, 0, 500, -1000, 1000);
        glMatrixMode(GL_MODELVIEW);
        modelview.load();
    }

    
    Engine::~Engine()
    {
    }
    

    Engine &Engine::render()
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(100, 100);
        glVertex2f(250, 400);
        glVertex2f(400, 100);
        glEnd();

        return *this;
    }


    Engine &Engine::clearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        return *this;
    }
} // namespace
