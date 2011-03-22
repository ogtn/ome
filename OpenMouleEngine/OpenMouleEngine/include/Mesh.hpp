////////////////////////////////////////////////////////////////////////
// Mesh.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MESH
#define HPP_MESH

#include "ShaderProgram.hpp"
#include "SceneNode.hpp"
#include "Texture2D.hpp"
#include "Color.hpp"
#include <vector>

namespace OpenMouleEngine
{
    #define BUFFER_OFFSET(i) ((char *)NULL + i)

    class IVertexArray
    {
    public:
        IVertexArray(std::string &name): name(name) {}
        virtual ~IVertexArray() {};

        virtual GLint size() const = 0;
        virtual GLint elementSize() const = 0;
        virtual GLint bytes() const = 0;
        virtual const char *data() const = 0;
        virtual void updateVBO(GLintptr offset) const = 0;
        virtual void enable(ShaderProgram &shader, GLintptr offset) const = 0;

    protected:
        std::string name;
    };


    template <typename T>
    class VertexArray: public IVertexArray
    {
    public:
        VertexArray(std::string name, std::vector<T> *vertices)
            : IVertexArray(name),
            vertices(vertices)
        {
        }

        ~VertexArray()
        {
            delete vertices;
        }

        GLint size() const
        {
            return vertices->size();
        }

        GLint elementSize() const
        {
            return sizeof(T);
        }

        GLint bytes() const
        {
            return vertices->size() * sizeof(T);
        }

        const char *data() const
        {
            return (char *) &(*vertices)[0];
        }

        void updateVBO(GLintptr offset) const
        {
            glBufferSubData(GL_ARRAY_BUFFER, offset, vertices->size() * sizeof(T), (char *) &(*vertices)[0]);
        }

        void enable(ShaderProgram &shader, GLintptr offset) const
        {
            GLint location = shader.getAttribLocation(name);

            glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset));
            glEnableVertexAttribArray(location);
        }

    private:
        std::vector<T> *vertices;
    };


    class Mesh: public Resource, public SceneNode
    {
    public:
        Mesh(std::string &name, IVertexArray *va);
        ~Mesh();

        virtual void sendUniforms() const;
        void render() const;    
        void setShader(ShaderProgram *s);
        void setTexture(Texture *t);
        void centerPivot(bool centerX = true, bool centerY = true, bool centerZ = true);

        // getters, needed to save mesh to file
        //const std::vector<vec3> &getPositions() const;
        //const std::vector<vec3> &getNormals() const;
        //const std::vector<vec2> &getTextureCoordinates() const;

    private:
        GLuint vbo;

        // offsets in VBO
        GLint positionsOffset;
        GLint coordinatesOffset;
        GLint normalsOffset;

        // buffers
        IVertexArray *va;

        ShaderProgram *shader;
        Texture *texture;
    };
} // namespace

#endif // HPP_MESH
