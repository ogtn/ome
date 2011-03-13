////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Engine.hpp"

#define BUFFER_OFFSET(i) ((char *)NULL + i)

namespace OpenMouleEngine
{
    Mesh::Mesh(std::string name):
    Resource(name),
    shader(NULL)
    {
        verticesPositions.push_back(0.1f);
        verticesPositions.push_back(0.1f);
        verticesPositions.push_back(0.9f);
        verticesPositions.push_back(0.9f);
        verticesPositions.push_back(0.9f);
        verticesPositions.push_back(0.1f);

        verticesPositions.push_back(0.1f);
        verticesPositions.push_back(0.9f);
        verticesPositions.push_back(0.1f);
        verticesPositions.push_back(0.1f);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * verticesPositions.size(), &verticesPositions[0], GL_STATIC_DRAW);
    }


    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &vbo);
    }


    void Mesh::render() const
    {
        Color c(.212f, .54f, .81f);

        // shader
        shader->bind();

        // uniforms
        shader->sendUniform("projection", Engine::getInstance()->getProjection());
        shader->sendUniform("modelview", Engine::getInstance()->getModelView());
        shader->sendUniform("prout", c);

        // buffer
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 2, GL_FLOAT, 0, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);

        // render
        glDrawArrays(GL_TRIANGLE_STRIP, 0, verticesPositions.size() / 2);

        // buffer
        glDisableVertexAttribArray(0);
        
        // shader
        shader->unbind();
    }


    void Mesh::setShader(ShaderProgram *s)
    {
        shader = s;
    }
} // namespace