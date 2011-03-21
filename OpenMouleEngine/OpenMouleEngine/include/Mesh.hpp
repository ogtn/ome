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
        Mesh(std::string name, std::vector<vec3> pos, std::vector<vec2> coord, std::vector<vec3> norm);
        ~Mesh();

        virtual void sendUniforms() const;
        void render() const;    
        void setShader(ShaderProgram *s);
        void centerPivot(bool centerX = true, bool centerY = true, bool centerZ = true);

        // getters, needed to save mesh to file
        const std::vector<vec3> &getPositions() const;
        const std::vector<vec2> &getTextureCoordinates() const;
        const std::vector<vec3> &getNormals() const;

    private:
        GLuint vbo;
        GLint positionOffset;
        GLint coordinatesOffset;
        GLint normalOffset;
        std::vector<vec3> verticesPositions;
        std::vector<vec2> verticesTextureCoordinates;
        std::vector<vec3> verticesNormals;
        ShaderProgram *shader;
    };
} // namespace

#endif // HPP_MESH
