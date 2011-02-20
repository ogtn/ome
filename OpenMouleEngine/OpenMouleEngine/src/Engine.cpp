////////////////////////////////////////////////////////////////////////
// Engine.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Engine.hpp"
#define GL3_PROTOTYPES 1
#include <GL/gl3.h>

namespace OpenMouleEngine
{
    Engine::Engine()
    {
        // OpenGL initialisation
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 800, 0, 600, -1000, 1000);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    
    Engine::~Engine()
    {
    }
    

    Engine &Engine::render()
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(400, 500);
        glVertex2f(100, 100);
        glVertex2f(700, 100);
        glEnd();

        return *this;
    }


    Engine &Engine::clearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        return *this;
    }
} // namespace
