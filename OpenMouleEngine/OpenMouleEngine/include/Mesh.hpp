////////////////////////////////////////////////////////////////////////
// Mesh.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MESH
#define HPP_MESH

#include "ShaderProgram.hpp"
#include "SceneNode.hpp"
#include "Resource.hpp"
#include "Color.hpp"
#include <GL/glew.h>
#include <vector>

namespace OpenMouleEngine
{
    class Mesh: public Resource, public SceneNode
    {
    public:
        Mesh(std::string name, std::vector<vec3> pos, std::vector<vec3> norm);
        ~Mesh();

        virtual void sendUniforms() const;
        void render() const;    
        void setShader(ShaderProgram *s);
        void centerPivot();

        // getters
        const std::vector<vec3> &getPositions() const;
        const std::vector<vec3> &getNormals() const;

    private:
        GLuint vbo;
        GLint positionOffset;
        GLint normalOffset;
        std::vector<vec3> verticesPositions;
        std::vector<vec3> verticesNormals;
        ShaderProgram *shader;
    };
} // namespace

#endif // HPP_MESH
