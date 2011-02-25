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

        std::string vertCode("\
                             #version 140\n\
                             in vec2 a_Vertex;\n\
                             uniform mat4 projection;\n\
                             uniform mat4 modelview;\n\
                             void main()\n\
                             {\n\
                             vec4 pos = modelview * vec4(a_Vertex, 0, 1.0);\n\
                             gl_Position = projection * pos;\n\
                             //gl_Position = vec4(a_Vertex, 0, 1) * modelview;\n\
                             }\n\
                             ");

        std::string fragCode("\
                             #version 140\n\
                             out vec4 outColor;\n\
                             void main()\n\
                             {\n\
                             outColor = vec4(0.3, 0.1, 0.7, 1);\n\
                             }\n\
                             ");

        Shader *vertShader = new Shader(std::string("Prout"), GL_VERTEX_SHADER, vertCode);
        Shader *fragShader = new Shader(std::string("Pouet"), GL_FRAGMENT_SHADER, fragCode);
        shader = new ShaderProgram(vertShader, fragShader);
        vertShader->compile();
        fragShader->compile();
        shader->link();

        // VBO
        vertices.push_back(-1.f);
        vertices.push_back(-1.f);
        vertices.push_back(1.f);
        vertices.push_back(-1.f);
        vertices.push_back(0.f);
        vertices.push_back(1.f);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    }

    
    Engine::~Engine()
    {
        delete shader;
        glDeleteBuffers(1, &vbo);
    }
    

    Engine &Engine::render()
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 2, GL_FLOAT, 0, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);
        shader->bind();
        shader->sendUniform("projection", projection);
        shader->sendUniform("modelview", modelview);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        shader->unbind();
        
        glDisableVertexAttribArray(0);

        return *this;
    }


    Engine &Engine::clearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        return *this;
    }
} // namespace
