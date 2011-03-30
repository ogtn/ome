////////////////////////////////////////////////////////////////////////
// Mesh.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MESH
#define HPP_MESH

#include "SceneNode.hpp"

namespace OpenMouleEngine
{
    // forward declarations
    class MeshData;
    class Material;

    class Mesh: public SceneNode
    {
    public:
        Mesh(const std::string &name, MeshData *geometry, ShaderProgram *shader = NULL, Material *material = NULL);
        ~Mesh();

        virtual void sendUniforms() const;
        void render() const;    
        void setShader(ShaderProgram *s);
        void setMaterial(Material *mat);
        void setRenderMode(GLenum m);
        void setPointSize(float size);
        const MeshData *data() const;

    private:
        MeshData *geometry;
        ShaderProgram *shader;
        Material *material;
        GLenum mode;
        float pointSize;
    };
} // namespace

#endif // HPP_MESH
