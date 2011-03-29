////////////////////////////////////////////////////////////////////////
// MeshData.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MESHDATA
#define HPP_MESHDATA

#include "ShaderProgram.hpp"
#include "Resource.hpp"
#include "Vector3.hpp"
#include <vector>
#include <map>

namespace OpenMouleEngine
{
    struct DataType
    {
        DataType(int size, GLenum glType)
            : size(size),
            glType(glType)
        {
        }

        int size;
        GLenum glType;
    };

    // types that can be sent to shaders via vertex attributes
    const DataType BYTE(sizeof(GLbyte),     GL_BYTE);
    const DataType UBYTE(sizeof(GLubyte),   GL_UNSIGNED_BYTE);
    const DataType SHORT(sizeof(GLshort),   GL_SHORT);
    const DataType USHORT(sizeof(GLushort), GL_UNSIGNED_SHORT);
    const DataType INT(sizeof(GLint),       GL_INT);
    const DataType UINT(sizeof(GLuint),     GL_UNSIGNED_INT);
    const DataType FLOAT(sizeof(GLfloat),   GL_FLOAT);
    const DataType DOUBLE(sizeof(GLdouble), GL_DOUBLE);
    //for error checking purpose only
    const DataType VOID(0,                  0);


    class Mesh;

    class MeshData: public Resource
    {
        struct VertexAttrib
        {
        public:
            VertexAttrib();
            VertexAttrib(char *data, GLsizeiptr offset, int nbElements, int nbSubElements, DataType type);
            ~VertexAttrib();

            void updateVBO();

            DataType type;
            char *data;
            GLsizeiptr offset;
            int nbSubElements;
            int nbElements;
        };


    public:
        template <typename T> 
        MeshData(const std::string &name, const std::string &attribName, std::vector<T> *data, DataType type = FLOAT);
        
        template <typename T>
        MeshData(const std::string &name, const std::string &attribName, T *data, unsigned int nbVertices, DataType type = FLOAT);
        
        //template <typename T> 
        //MeshData(const std::string &name, T *data, int nbVertices);   
        
        ~MeshData();

        template <typename T>
        void addSubArray(const std::string &attribName, std::vector<T> *data, DataType type = FLOAT);

        //template <typename T> 
        //void addSubArray(const std::string &attribName, T *data, int nbVertices, GLenum type = GL_FLOAT);

        //template <typename T>
        //void addSubArray(const std::string &attribName, int nbSubElements = 3, GLenum type = GL_FLOAT);

        template <typename T>
        T *rawData(const std::string &name);

        Mesh *getMesh();
        //const std::vector<Mesh *> &getMeshes() const;
        void render(ShaderProgram &shader, GLenum mode);
        void finalize();

        //void print()
        //{
        //    std::cerr << "Le VBO contient " << nbVertices << " sommets, pour un total de " << byteSize << " octets" << std::endl;
        //
        //    if(finalized)
        //        std::cerr << "Il est finalise" << std::endl;
        //    else
        //        std::cerr << "Il n'est pas finalise" << std:: endl;

        //    if(interleaved)
        //        std::cerr << "Il est entrelace" << std::endl;
        //    else
        //        std::cerr << "Il n'est pas entrelace" << std:: endl;


        //    std::cerr << "Il est constitue de:" << std::endl;

        //    std::map<std::string, VertexAttrib>::iterator it;

        //    for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
        //    {
        //        std::cerr << it->first << " avec " << it->second.nbSubElements;
        //        std::cerr << " sous elements de taille " << it->second.type.size;
        //        std::cerr << ", d'offset " << it->second.offset << std::endl;
        //    }
        //}

    private:
        typedef std::map<std::string, VertexAttrib> AttribMap;
        typedef std::map<std::string, VertexAttrib>::iterator AttribIterator;

        #define BUFFER_OFFSET(i) ((char *)NULL + i)

        GLuint vbo;
        std::vector<Mesh *> meshes;
        AttribMap vertexAttribs;
        unsigned int nbVertices;
        unsigned int byteSize;
        bool interleaved;
        bool finalized;
    };

#include "MeshData.inl"

} // namespace

#endif // HPP_MESHDATA
