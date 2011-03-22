////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Engine.hpp"

namespace OpenMouleEngine
{
    Mesh::Mesh(std::string &name, IVertexArray *va)
        : Resource(name),
        va(va),
        shader(NULL),
        texture(NULL)
    {
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        GLsizeiptr size = va->bytes();

        // positions
        //positions = *pPositions;
        positionsOffset = 0;
        //size += positions.size() * sizeof(vec3);

        // normals
        //if(pNormals)
        //{
        //    normals = *pNormals;
        //    normalsOffset = size;
        //    size += normals.size() * sizeof(vec3);
        //}

        // texture coordinates
        //if(pCoordinates)
        //{
        //    coordinates = *pCoordinates;
        //    coordinatesOffset = size;
        //    size += coordinates.size() * sizeof(vec2);
        //}

        // memory allocation
        glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

        // buffer initialisation
        va->updateVBO(0);
        
        //glBufferSubData(GL_ARRAY_BUFFER, positionsOffset, va->bytes(), va->data());

        /*if(pNormals)
            glBufferSubData(GL_ARRAY_BUFFER, normalsOffset, sizeof(vec3) * normals.size(), &normals[0]);

        if(pCoordinates)
            glBufferSubData(GL_ARRAY_BUFFER, coordinatesOffset, sizeof(vec2) * coordinates.size(), &coordinates[0]);*/

        va;
    }


    Mesh::~Mesh()
    {
        delete va;
        glDeleteBuffers(1, &vbo);
    }


    void Mesh::sendUniforms() const
    {
        //shader->sendUniform("texture0", *texture);
        shader->sendUniform("camera", *Engine::getInstance()->getCamera());
    }


    void Mesh::render() const
    {
        // shader
        shader->bind();

        // uniforms
        sendUniforms();

        // textures
        glActiveTexture(GL_TEXTURE0 + 0);
        texture->bind(); 

        // buffers
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        va->enable(*shader, positionsOffset);
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(positionsOffset));
        //glEnableVertexAttribArray(0);
        //glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(normalsOffset));
        //glEnableVertexAttribArray(1);
        //glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(coordinatesOffset));
        //glEnableVertexAttribArray(2);

        // render
        glDrawArrays(GL_TRIANGLES, 0, va->size());

        // buffer
        //glDisableVertexAttribArray(2);
        //glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);

        // shader
        shader->unbind();
    }


    void Mesh::setShader(ShaderProgram *s)
    {
        shader = s;
    }


    void Mesh::setTexture(Texture *t)
    {
        texture = t;
    }


    void Mesh::centerPivot(bool centerX, bool centerY, bool centerZ)
    {
        //unsigned int i;
        //
        //vec3 posMin(positions[0]);
        //vec3 posMax(positions[0]);

        //for(i = 0; i < positions.size(); i++)
        //{
        //    posMin.x = MIN(posMin.x, positions[i].x);
        //    posMin.y = MIN(posMin.y, positions[i].y);
        //    posMin.z = MIN(posMin.z, positions[i].z);

        //    posMax.x = MAX(posMax.x, positions[i].x);
        //    posMax.y = MAX(posMax.y, positions[i].y);
        //    posMax.z = MAX(posMax.z, positions[i].z);
        //}

        //vec3 diff(vec3() - (posMax + posMin) / 2.f);

        //if(!centerX)
        //    diff.x = 0;

        //if(!centerY)
        //    diff.y = 0;

        //if(!centerZ)
        //    diff.z = 0;

        //for(i = 0; i < positions.size(); i++)
        //    positions[i] = positions[i] + diff;

        //glBufferSubData(GL_ARRAY_BUFFER, positionsOffset, sizeof(vec3) * positions.size(), &positions[0]);
    }


    //const std::vector<vec3> &Mesh::getPositions() const
    //{
    //    return positions;
    //}
    //

    //const std::vector<vec3> &Mesh::getNormals() const
    //{
    //    return normals;
    //}


    //const std::vector<vec2> &Mesh::getTextureCoordinates() const
    //{
    //    return coordinates;
    //}
} // namespace
