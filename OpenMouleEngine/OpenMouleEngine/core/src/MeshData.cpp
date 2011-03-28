////////////////////////////////////////////////////////////////////////
// MeshData.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MeshData.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    MeshData::MeshData(const std::string &name, VertexArray *vertexArray)
        : Resource(name),
        vertexArray(vertexArray),
        meshes()
    {
        // creating VBO
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // allocate memory for the VBO
        vertexArray->finalize();
        glBufferData(GL_ARRAY_BUFFER, vertexArray->size(), NULL, GL_STATIC_DRAW);

        // vertex arrays initialisation
        vertexArray->updateVBO();
    }


    MeshData::~MeshData()
    {
        // destroy the VBO
        glDeleteBuffers(1, &vbo);

        std::cerr << "il manque un truc la..." << std::endl;
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
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        vertexArray->enable(shader);
        glDrawArrays(mode, 0, vertexArray->nbElements());
        vertexArray->disable(shader);
    }
} // namespace
