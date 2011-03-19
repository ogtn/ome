////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Engine.hpp"

#define BUFFER_OFFSET(i) ((char *)NULL + i)

namespace OpenMouleEngine
{
    Mesh::Mesh(std::string name, std::vector<vec3> pos, std::vector<vec3> norm)
        : Resource(name),
        verticesPositions(pos),
        verticesNormals(norm),
        shader(NULL)
    {
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        positionOffset = 0;
        normalOffset = sizeof(vec3) * verticesPositions.size();

        glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * (verticesPositions.size() + verticesNormals.size()), NULL, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, positionOffset, sizeof(vec3) * verticesPositions.size(), &verticesPositions[0]);
        glBufferSubData(GL_ARRAY_BUFFER, normalOffset, sizeof(vec3) * verticesNormals.size(), &verticesNormals[0]);
    }


    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &vbo);
    }


    void Mesh::sendUniforms() const
    {
        //shader->sendUniform("myLight", Color(.212f, .54f, .81f));
        shader->sendUniform("camera", *Engine::getInstance()->getCamera());
    }


    void Mesh::render() const
    {
        // shader
        shader->bind();

        // uniforms
        sendUniforms();

        // buffers
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(positionOffset));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(normalOffset));
        glEnableVertexAttribArray(1);

        // render
        glDrawArrays(GL_TRIANGLES, 0, verticesPositions.size());

        // buffer
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);

        // shader
        shader->unbind();
    }


    void Mesh::setShader(ShaderProgram *s)
    {
        shader = s;
    }


    void Mesh::centerPivot()
    {
        unsigned int i;
        
        vec3 posMin(verticesPositions[0]);
        vec3 posMax(verticesPositions[0]);

        for(i = 0; i < verticesPositions.size(); i++)
        {
            posMin.x = MIN(posMin.x, verticesPositions[i].x);
            posMin.y = MIN(posMin.y, verticesPositions[i].y);
            posMin.z = MIN(posMin.z, verticesPositions[i].z);

            posMax.x = MAX(posMax.x, verticesPositions[i].x);
            posMax.y = MAX(posMax.y, verticesPositions[i].y);
            posMax.z = MAX(posMax.z, verticesPositions[i].z);
        }

        vec3 diff(vec3() - (posMax + posMin) / 2.f);

        for(i = 0; i < verticesPositions.size(); i++)
            verticesPositions[i] = verticesPositions[i] + diff;

        glBufferSubData(GL_ARRAY_BUFFER, positionOffset, sizeof(vec3) * verticesPositions.size(), &verticesPositions[0]);
    }
} // namespace
