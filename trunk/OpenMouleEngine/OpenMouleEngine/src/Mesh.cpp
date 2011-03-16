////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Engine.hpp"

#define BUFFER_OFFSET(i) ((char *)NULL + i)

namespace OpenMouleEngine
{
    Mesh::Mesh(std::string name, std::vector<vec3> pos):
    Resource(name),
    shader(NULL),
    verticesPositions(pos)
    {
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * verticesPositions.size(), &verticesPositions[0], GL_STATIC_DRAW);
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
        Engine::getInstance()->getCamera()->send();
        shader->sendUniform("prout", c);

        // buffer
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, 0, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);

        // render
        glDrawArrays(GL_TRIANGLES, 0, verticesPositions.size());

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
