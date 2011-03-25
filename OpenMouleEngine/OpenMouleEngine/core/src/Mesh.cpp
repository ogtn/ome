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
        material()
    {
        // creating VBO
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // compute offsets of each vertex array
        GLsizeiptr size = 0;
        GLsizei stride = 0;

        for(unsigned int i = 0; i < vertexArrays.size(); i++)
        {
            offsets.push_back(size);
            //stride += vertexArrays[i]->elementSize();
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
        vec3 pos = getPosition();

        shader->sendUniform("mdlPosition", pos);
        shader->sendUniform("camera", *Engine::getInstance()->getCamera());
        shader->sendUniform("mat", *material);
    }


    void Mesh::render() const
    {
        // shader
        shader->bind();

        // uniforms
        sendUniforms();

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


    void Mesh::setMaterial(Material *mat)
    {
        material = mat;
    }


    const std::vector<IVertexArray *> &Mesh::getArrays() const
    {
        return vertexArrays;
    }


    //const std::vector<vec3> &Mesh::getPositions() const
    //{
    //    return positions;
    //}


    //const std::vector<vec3> &Mesh::getNormals() const
    //{
    //    return normals;
    //}


    //const std::vector<vec2> &Mesh::getTextureCoordinates() const
    //{
    //    return coordinates;
    //}
} // namespace
