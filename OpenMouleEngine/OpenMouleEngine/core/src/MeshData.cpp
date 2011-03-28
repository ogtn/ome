////////////////////////////////////////////////////////////////////////
// MeshData.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MeshData.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    MeshData::MeshData(const std::string &name, std::vector<IVertexArray *> &vertexArrays)
        : Resource(name),
        vertexArrays(vertexArrays),
        offsets(),
        meshes()
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


    MeshData::MeshData(const std::string &name, VertexArray2 *va)
        : Resource(name),
        va(va),
        offsets(),
        meshes()
    {
        // creating VBO
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // allocate memory for the VBO
        va->finalize();
        glBufferData(GL_ARRAY_BUFFER, va->size(), NULL, GL_STATIC_DRAW);

        // vertex arrays initialisation
        va->updateVBO();
    }


    MeshData::~MeshData()
    {
        // destroy the VBO
        glDeleteBuffers(1, &vbo);

        // free the vertex arrays
        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            delete vertexArrays[i];
    }


    Mesh *MeshData::getMesh() const
    {
        return new Mesh(this);
    }


    //const std::vector<Mesh *> &MeshData::getMeshes() const
    //{
    //    return vertexArrays;
    //}


    void MeshData::render(ShaderProgram &shader, GLenum mode) const
    {
        if(name.name == "grid2")
            return render2(shader, mode);

        // buffers
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            vertexArrays[i]->enable(shader, offsets[i]);

        // render
        glDrawArrays(mode, 0, vertexArrays[0]->size());

        // buffer
        for(unsigned int i = 0; i < vertexArrays.size(); i++)
            vertexArrays[i]->disable(shader);
    }


    void MeshData::render2(ShaderProgram &shader, GLenum mode) const
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        va->enable(shader);
        glDrawArrays(mode, 0, va->nbElements());
        va->disable(shader);
    }


    const std::vector<IVertexArray *> &MeshData::arrays() const
    {
        return vertexArrays;
    }
} // namespace
