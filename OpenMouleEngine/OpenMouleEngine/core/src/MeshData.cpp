////////////////////////////////////////////////////////////////////////
// MeshData.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MeshData.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    MeshData::~MeshData()
    {
        // destroying VBO
        glDeleteBuffers(1, &vbo);

        std::cerr << "il manque un truc la..." << std::endl;
    }


    void MeshData::addSubArray(const std::string &attribName, int nbSubElements, DataType type)
    {
        if(finalized)
        {
            std::cerr << "addSubArray(): impossible d'ajouter dans un vertex array finalise" << std::endl;
            return;
        }

        if(!interleaved)
        {
            std::cerr << "addSubArray(): impossible d'ajouter dans un vertex array non entrelace" << std::endl;
            return;
        }

        if(vertexAttribs.find(attribName) != vertexAttribs.end())
        {
            std::cerr << "addSubArray(): impossible d'ecraser des donnees" << std::endl;
            return;
        }

        vertexAttribs[attribName] = VertexAttrib(tmpData, offset, nbVertices, nbSubElements, type);
        byteSize += nbVertices * nbSubElements * type.size;
        offset += nbSubElements * type.size;
    }


    Mesh *MeshData::getMesh()
    {
        return new Mesh(this);
    }


    //const std::vector<Mesh *> &MeshData::getMeshes() const
    //{
    //    return vertexArrays;
    //}


    void MeshData::render(ShaderProgram &shader, GLenum mode)
    {
        if(!finalized)
            finalize();

        AttribIterator it;
        GLint location;

        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // enabling vertex attribues
        for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
        {
            location = shader.getAttribLocation(it->first);

            if(interleaved)
                glVertexAttribPointer(location, it->second.nbSubElements, it->second.type.glType, GL_FALSE, offset, BUFFER_OFFSET(it->second.offset));
            else
                glVertexAttribPointer(location, it->second.nbSubElements, it->second.type.glType, GL_FALSE, 0, BUFFER_OFFSET(it->second.offset));
                
            glEnableVertexAttribArray(location);
        }


        glDrawArrays(mode, 0, nbVertices);

        // disabling vertex attributes
        for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
            glDisableVertexAttribArray(shader.getAttribLocation(it->first));
    }


    void MeshData::finalize()
    {
        // allocate memory for the VBO
        glBufferData(GL_ARRAY_BUFFER, byteSize, NULL, GL_STATIC_DRAW);

        // vertex arrays initialisation
        AttribIterator it;

        for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
            it->second.updateVBO();

        finalized = true;
    }


    MeshData::VertexAttrib::VertexAttrib()
        : type(VOID),
        data(NULL),
        offset(0),
        nbSubElements(0),
        nbElements(0)
    {
    }


    MeshData::VertexAttrib::VertexAttrib(char *data, GLsizeiptr offset, int nbElements, int nbSubElements, DataType type)
        : type(type),
        data(data),
        offset(offset),
        nbSubElements(nbSubElements),
        nbElements(nbElements)
    {
    }

    MeshData::VertexAttrib::~VertexAttrib()
    {
    }


    void MeshData::VertexAttrib::updateVBO()
    {
        glBufferSubData(GL_ARRAY_BUFFER, offset, nbElements * nbSubElements * type.size, data);
    }
} // namespace
