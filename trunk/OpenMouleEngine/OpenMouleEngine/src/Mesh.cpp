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
        verticesPositions.push_back(-1.f);
        verticesPositions.push_back(-1.f);
        verticesPositions.push_back(1.f);
        verticesPositions.push_back(-1.f);
        verticesPositions.push_back(0.f);
        verticesPositions.push_back(1.f);

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
        // shader
        shader->bind();

        // uniforms
        shader->sendUniform("projection", Engine::getInstance()->getProjection());
        shader->sendUniform("modelview", Engine::getInstance()->getModelView());

        // buffer
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 2, GL_FLOAT, 0, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);

        // render
        glDrawArrays(GL_TRIANGLES, 0, 3);

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
