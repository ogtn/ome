////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Engine.hpp"

namespace OpenMouleEngine
{
    Mesh::Mesh(const std::string &name, std::vector<IVertexArray *> &vertexArrays)
        : Resource(name),
        vertexArrays(vertexArrays),
        shader(NULL),
        texture(NULL)
    {
        // creating VBO
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // compute offsets of each vertex array
        GLsizeiptr size = 0;

        for(unsigned int i = 0; i < vertexArrays.size(); i++)
        {
            offsets.push_back(size);
            size += vertexArrays[i]->bytes();
        }

        // allocate memory for the VBO
        glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

        // vertex arrays initialisation
        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            vertexArrays[i]->updateVBO(offsets[i]);
    }


    Mesh::~Mesh()
    {
        // destroy the VBO
        glDeleteBuffers(1, &vbo);

        // free the vertex arrays
        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            delete vertexArrays[i];
    }


    void Mesh::sendUniforms() const
    {
        shader->sendUniform("texture0", *texture);
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

        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            vertexArrays[i]->enable(*shader, offsets[i]);

        // render
        glDrawArrays(GL_TRIANGLES, 0, vertexArrays[0]->size());

        // buffer
        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            vertexArrays[i]->disable(*shader);

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
