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
        Mesh(std::string name, std::vector<vec3> pos);

        ~Mesh();

        void render() const;
    
        void setShader(ShaderProgram *s);

    private:
        GLuint vbo;
        std::vector<vec3> verticesPositions;
        ShaderProgram *shader;
    };
} // namespace

#endif // HPP_MESH
