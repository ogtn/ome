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

    class VertexArray
    {
        struct VertexAttrib
        {
        private:
            #define BUFFER_OFFSET(i) ((char *)NULL + i)

        public:
            VertexAttrib()
                : data(NULL),
                offset(0),
                type(VOID),
                nbSubElements(0),
                nbElements(0)
            {
            }

            VertexAttrib(char *data, GLsizeiptr offset, int nbElements, int nbSubElements, DataType type)
                : type(type),
                data(data),
                nbSubElements(nbSubElements),
                offset(offset),
                nbElements(nbElements)
            {
            }

            ~VertexAttrib()
            {
            }


            void updateVBO()
            {
                glBufferSubData(GL_ARRAY_BUFFER, offset, nbElements * nbSubElements * type.size, data);
            }

            char *data;
            GLsizeiptr offset;
            DataType type;
            int nbSubElements;
            int nbElements;
        };

    public:
        template <typename T> 
        VertexArray(const std::string &attribName, std::vector<T> *data, DataType type = FLOAT)
            : vertexAttribs(),
            nbVertices(),
            interleaved(false),
            finalized(false),
            byteSize(0)
        {
            nbVertices = data->size();
            vertexAttribs[attribName] = VertexAttrib((char *)(&(*data)[0]), byteSize, nbVertices, sizeof(T) / type.size, type);
            byteSize += data->size() * sizeof(T);
        }

        template <typename T> 
        VertexArray(const std::string &attribName, T *data, unsigned int nbVertices, DataType type = FLOAT)
            : vertexAttribs(),
            nbVertices(nbVertices),
            interleaved(false),
            finalized(false),
            byteSize(0)
        {
            vertexAttribs[attribName] = VertexAttrib(data, byteSize, sizeof(T) / type.size, type);
            byteSize += nbVertices * sizeof(T);
        }

        //template <typename T> 
        //VertexArray2(T *data, int nbVertices)
        //    : vertexAttribs(),
        //    nbVertices(nbVertices),
        //    offset(0),
        //    interleaved(true),
        //    finalized(false)
        //{
        //}

        ~VertexArray()
        {
            std::cerr << "penser à liberer des trucs ici!" << std::endl;
        }

        template <typename T>
        void addSubArray(const std::string &attribName, std::vector<T> *data, DataType type = FLOAT)
        {
            if(data->size() != nbVertices)
            {
                std::cerr << "addSubArray(): taille du vertex array invalide" << std::endl;
                return;
            }

            if(finalized)
            {
                std::cerr << "addSubArray(): impossible d'ajouter dans un vertex array finalise" << std::endl;
                return;
            }

            if(interleaved)
            {
                std::cerr << "addSubArray(): impossible d'ajouter dans un vertex array entrelace" << std::endl;
                return;
            }

            if(vertexAttribs.find(attribName) != vertexAttribs.end())
            {
                std::cerr << "addSubArray(): impossible d'ecraser des donnees" << std::endl;
                return;
            }

            vertexAttribs[attribName] = VertexAttrib((char *)(&(*data)[0]), byteSize, nbVertices, sizeof(T) / type.size, type);
            byteSize += data->size() * sizeof(T);
        }

        //template <typename T> 
        //void addSubArray(const std::string &attribName, T *data, int nbVertices, GLenum type = GL_FLOAT);

        //template <typename T>
        //void addSubArray(const std::string &attribName, int nbSubElements = 3, GLenum type = GL_FLOAT);

        //template <typename T> 
        //T &operator[](int index);

        void finalize()
        {
            finalized = true;
        }


        unsigned int size()
        {
            if(!finalized)
                std::cerr << "size(): impossible de retourner la taille d'unvertex array non finalise" << std::endl;

            return byteSize;
        }


        unsigned int nbElements()
        {
            return nbVertices;
        }


        void updateVBO()
        {
            std::map<std::string, VertexAttrib>::iterator it;

            for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
                it->second.updateVBO();
        }


        void enable(ShaderProgram &shader)
        {
            std::map<std::string, VertexAttrib>::iterator it;
            GLint location;

            for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
            {
                location = shader.getAttribLocation(it->first);

                glVertexAttribPointer(location, it->second.nbSubElements, it->second.type.glType, GL_FALSE, 0, BUFFER_OFFSET(it->second.offset));
                glEnableVertexAttribArray(location);
            }
        }


        void disable(ShaderProgram &shader)
        {
            std::map<std::string, VertexAttrib>::iterator it;

            for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
                glDisableVertexAttribArray(shader.getAttribLocation(it->first));
        }


        template <typename T>
        T *rawData(const std::string &name)
        {
            if(vertexAttribs.find(name) == vertexAttribs.end())
            {
                std::cerr << "l'attribut " + name + " n'existe pas" << std::endl;
            }

            return reinterpret_cast<T*>(vertexAttribs[name].data);
        }


        //friend std::ostream &operator<<(std::ostream &ostr, const VertexArray2 &va);
        void print()
        {
            std::cerr << "Le VBO contient " << nbVertices << " sommets, pour un total de " << byteSize << " octets" << std::endl;
        
            if(finalized)
                std::cerr << "Il est finalise" << std::endl;
            else
                std::cerr << "Il n'est pas finalise" << std:: endl;

            if(interleaved)
                std::cerr << "Il est entrelace" << std::endl;
            else
                std::cerr << "Il n'est pas entrelace" << std:: endl;


            std::cerr << "Il est constitue de:" << std::endl;

            std::map<std::string, VertexAttrib>::iterator it;

            for(it = vertexAttribs.begin(); it != vertexAttribs.end(); ++it)
            {
                std::cerr << it->first << " avec " << it->second.nbSubElements;
                std::cerr << " sous elements de taille " << it->second.type.size;
                std::cerr << ", d'offset " << it->second.offset << std::endl;
                std::cerr << "Premier element: " << *rawData<vec3>(it->first) << std::endl;
            }
        }

    private:
        std::map<std::string, VertexAttrib> vertexAttribs;
        unsigned int nbVertices;
        unsigned int byteSize;
        bool interleaved;
        bool finalized;
    };





    class Mesh;

    class MeshData: public Resource
    {
    public:
        MeshData(const std::string &name, VertexArray *va);
        ~MeshData();

        Mesh *getMesh() const;
        //const std::vector<Mesh *> &getMeshes() const;
        void render(ShaderProgram &shader, GLenum mode) const;

    private:
        GLuint vbo;
        std::vector<Mesh *> meshes;
        VertexArray *vertexArray;
    };
} // namespace

#endif // HPP_MESHDATA
