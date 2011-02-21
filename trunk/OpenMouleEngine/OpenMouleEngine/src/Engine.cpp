////////////////////////////////////////////////////////////////////////
// Engine.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Engine.hpp"
#include <iostream>

#define BUFFER_OFFSET(i) ((char *)NULL + i)

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

        // VBO
        vertices.push_back(100);
        vertices.push_back(100);
        vertices.push_back(250);
        vertices.push_back(400);
        vertices.push_back(400);
        vertices.push_back(100);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    }

    
    Engine::~Engine()
    {
        glDeleteBuffers(1, &vbo);
    }
    

    Engine &Engine::render()
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 2, GL_FLOAT, 0, 0, BUFFER_OFFSET(0));
        //glVertexPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);
        //glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);
        //glDisableClientState(GL_VERTEX_ARRAY);

        return *this;
    }


    Engine &Engine::clearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        return *this;
    }
} // namespace
