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
    class Mesh: public Resource, public SceneNode
    {
    public:
        Mesh(std::string &name, std::vector<vec3> *pos, std::vector<vec3> *norm, std::vector<vec2> *coord);
        ~Mesh();

        virtual void sendUniforms() const;
        void render() const;    
        void setShader(ShaderProgram *s);
        void setTexture(Texture *t);
        void centerPivot(bool centerX = true, bool centerY = true, bool centerZ = true);

        // getters, needed to save mesh to file
        const std::vector<vec3> &getPositions() const;
        const std::vector<vec3> &getNormals() const;
        const std::vector<vec2> &getTextureCoordinates() const;

    private:
        GLuint vbo;

        // offsets in VBO
        GLint positionsOffset;
        GLint coordinatesOffset;
        GLint normalsOffset;

        // pointers
        std::vector<vec3> *pPositions;
        std::vector<vec2> *pCoordinates;
        std::vector<vec3> *pNormals;

        // references
        std::vector<vec3> &positions;
        std::vector<vec2> &coordinates;
        std::vector<vec3> &normals;

        ShaderProgram *shader;
        Texture *texture;
    };
} // namespace

#endif // HPP_MESH
