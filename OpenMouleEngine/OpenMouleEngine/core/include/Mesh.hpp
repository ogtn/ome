////////////////////////////////////////////////////////////////////////
// Mesh.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MESH
#define HPP_MESH

#include "ShaderProgram.hpp"
#include "Renderable.hpp"
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
        IVertexArray(const std::string &name): name(name) {}
        virtual ~IVertexArray() {};

        virtual GLint size() const = 0;
        virtual GLint elementSize() const = 0;
        virtual GLint bytes() const = 0;
        virtual const char *data() const = 0;
        virtual void updateVBO(GLintptr offset) const = 0;
        virtual void enable(ShaderProgram &shader, GLintptr offset, GLsizei stride = 0) const = 0;
        virtual void disable(ShaderProgram &shader) const = 0;

    protected:
        std::string name;
    };


    template <typename T, GLint nbElement, GLenum type>
    class VertexArray: public IVertexArray
    {
    public:
        VertexArray(const std::string &name, std::vector<T> *vertices)
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
            return (char *)&vertices[0];
        }

        void updateVBO(GLintptr offset) const
        {
            glBufferSubData(GL_ARRAY_BUFFER, offset, vertices->size() * sizeof(T), (char *) &(*vertices)[0]);
        }

        void enable(ShaderProgram &shader, GLintptr offset, GLsizei stride = 0) const
        {
            GLint location = shader.getAttribLocation(name);

            glVertexAttribPointer(location, nbElement, type, GL_FALSE, stride, BUFFER_OFFSET(offset));
            glEnableVertexAttribArray(location);
        }

        void disable(ShaderProgram &shader) const
        {
            glDisableVertexAttribArray(shader.getAttribLocation(name));
        }

    private:
        std::vector<T> *vertices;
    };


    class Mesh: public Resource, public SceneNode
    {
    public:
        Mesh(const std::string &name, std::vector<IVertexArray *> &vertexArrays);
        ~Mesh();

        virtual void sendUniforms() const;
        void render() const;    
        void setShader(ShaderProgram *s);
        void setTexture(Texture *t);
        void setTexture(const std::string &name);
        const std::vector<IVertexArray *> &getArrays() const;
        
    private:
        GLuint vbo;

        // buffers and associated offsets
        std::vector<IVertexArray *> vertexArrays;
        std::vector<GLsizeiptr> offsets;

        // temporary
        ShaderProgram *shader;
        std::vector<Texture *> textures;
    };
} // namespace

#endif // HPP_MESH
